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

int main() 
{int t;
scanf("%d",&t);
for(int p=0;p<t;p++)
	{
		int m;int n;
		sc(m);sc(n);
		ll a[m+2][n+2];
		for(int i=0;i<m+2;i++)
		{
			for(int j=0;j<n+2;j++)
			{
				a[i][j]=-1;
			}
		}
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				scanf("%lld",&a[i][j]);
			}
		}
		int flag1=m*n;
		int i1=1;int j1=1;
		char dir='r';
		
		while(flag1!=0)
		{	int tt=0;
		
			if(dir=='r'){cout<<(a[i1][j1])*(a[i1][j1])<<" ";a[i1][j1]=-1;tt=1;if(a[i1][j1+1]==-1){dir='b';i1++;}else j1++;}
			else if(dir=='b'){cout<<(a[i1][j1])*(a[i1][j1])<<" ";a[i1][j1]=-1;tt=1;if(a[i1+1][j1]==-1){dir='l';j1--;}else i1++;}
			else if(dir=='l'){cout<<(a[i1][j1])*(a[i1][j1])<<" ";a[i1][j1]=-1;tt=1;if(a[i1][j1-1]==-1){dir='u';i1--;}else j1--;}
			else if(dir=='u'){cout<<(a[i1][j1])*(a[i1][j1])<<" ";a[i1][j1]=-1;tt=1;if(a[i1-1][j1]==-1){dir='r';j1++;}else i1--;}
			//if(tt==0)flag=1;
			flag1--;
		}
		cout<<endl;
		
	}
}