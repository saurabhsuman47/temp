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

#from sklearn.linear_model import LogisticRegression
#clf = LogisticRegression()
#from sklearn.tree import DecisionTreeClassifier
#clf = DecisionTreeClassifier()
from sklearn.ensemble import RandomForestClassifier
clf = RandomForestClassifier(max_depth=4, n_estimators=10)
#from sklearn.naive_bayes import GaussianNB
#clf = GaussianNB()
#from sklearn.svm import SVC
#clf = SVC(gamma=2, C=1)
#from sklearn.neural_network import MLPClassifier
#clf = MLPClassifier()
#from sklearn.ensemble import AdaBoostClassifier
#clf = AdaBoostClassifier()

clf.fit(X, y)
y_pred = clf.predict(X)

from sklearn.metrics import confusion_matrix
cm = confusion_matrix(y, y_pred)
print clf.score(X, y)

#test
test_filepath =  "/home/saurabh/Downloads/test.csv"
df1 = pd.read_csv(test_filepath)
pass_id = df1.iloc[:, 0]
X_test = df1.iloc[:, [1, 3, 4, 5, 6, 8]]
labelencoder = preprocessing.LabelEncoder()
onehotencoder = preprocessing.OneHotEncoder()
X_test.iloc[:, 1] = labelencoder.fit_transform(X_test.iloc[:, 1])
X_test = X_test.fillna(X.mean())
y_test_pred = clf.predict(X_test)
output = pd.concat([pass_id, pd.DataFrame(y_test_pred, columns=['Survived'])], axis = 1)
output.to_csv("/home/saurabh/Downloads/foo.csv", index=False)


