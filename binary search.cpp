#include <iostream>
using namespace std;
#include <cstring>
#include <cstdio>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <stack>
#include <queue>
double eps=1e-8;
typedef long long ll;
const ll mod=1000000007ll;
#define sc(x) scanf("%d",&(x))

void funct(int a[],int n,int item)
{
	int beg=1;
	int end=n;

	int mid=(beg+end)/2;                       // Find Mid Location of Array

	while(beg<=end && a[mid]!=item)      // Compare Item and Value of Mid
	{
		if(a[mid]<item)
		beg=mid+1;
		else
		end=mid-1;

		mid=(beg+end)/2;
	}

	if(a[mid]==item)
	{
		cout<<mid+1<<endl;
	}
	else
	{
		cout<<"NOT FOUND"<<endl;
	}
}


int main() 
{int n,m;
scanf("%d",&n);
sc(m);
int a[n];
for(int p=0;p<n;p++)
	{scanf("%d",&a[p]);}
for(int p=0;p<m;p++)
{
	int t;
	
	sc(t);
	//cout<<t<<endl;
	funct(a,n,t);
}
}