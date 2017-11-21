# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

import numpy as np
import scipy as sp
import pandas as pd
import os

file_path = "/home/saurabh/Downloads/train.csv"
df = pd.read_csv(file_path)

from sklearn import preprocessing
X = df.iloc[:, [2, 4, 5, 6, 7, 9]]
labelencoder = preprocessing.LabelEncoder()
onehotencoder = preprocessing.OneHotEncoder()
X.iloc[:, 1] = labelencoder.fit_transform(X.iloc[:, 1])
#X.iloc[:, -1] = labelencoder.fit_transform(X.iloc[:, -1])
#A = onehotencoder.fit_transform(X.iloc[:, -1:]).toarray()
#X = pd.concat([X, pd.DataFrame(A)], axis=1)
X = X.fillna(X.mean())
#X = preprocessing.scale(X)
y = df.iloc[:, 1]

# Splitting the dataset into the Training set and Test set
from sklearn.cross_validation import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.25, random_state = 0)

#from sklearn.linear_model import LogisticRegression
#clf = LogisticRegression()
#from sklearn.tree import DecisionTreeClassifier
#clf = DecisionTreeClassifier()
from sklearn.ensemble import RandomForestClassifier
#clf = RandomForestClassifier()
clf = RandomForestClassifier(max_depth=6, n_estimators=10)
#from sklearn.naive_bayes import GaussianNB
#clf = GaussianNB()
#from sklearn.svm import SVC
#clf = SVC(gamma=2, C=1)
#from sklearn.neural_network import MLPClassifier
#clf = MLPClassifier()
#from sklearn.ensemble import AdaBoostClassifier
#clf = AdaBoostClassifier()
#from sklearn.neighbors import KNeighborsClassifier
#clf = KNeighborsClassifier(n_neighbors=5, metric='minkowski', p = 2)

clf.fit(X_train, y_train)


from sklearn.metrics import confusion_matrix
y_pred = clf.predict(X_test)
cm = confusion_matrix(y_test, y_pred)
print "train score" , clf.score(X_train, y_train)
print "test score" , clf.score(X_test, y_test)

#test
test_filepath =  "/home/saurabh/Downloads/test.csv"
df1 = pd.read_csv(test_filepath)
pass_id = df1.iloc[:, 0]
X_test = df1.iloc[:, [1, 3, 4, 5, 6, 8]]
labelencoder = preprocessing.LabelEncoder()
X_test.iloc[:, 1] = labelencoder.fit_transform(X_test.iloc[:, 1])
X_test = X_test.fillna(X_test.mean())
y_test_pred = clf.predict(X_test)
output = pd.concat([pass_id, pd.DataFrame(y_test_pred, columns=['Survived'])], axis = 1)
output.to_csv("/home/saurabh/Downloads/foo.csv", index=False)


