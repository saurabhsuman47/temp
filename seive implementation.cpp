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

int main() 
{int n=1000000;
	int a[1000000]={0};
	a[0]=1;a[1]=1;
	int b[78498];
	 int count1=0;

	
	int t=1000;
	for(int i=2;i<=1000;)
		{	int k=i+1;
			
			for(int j=2;(j*i)<=n;j++)
			{
				int temp1=i*j;
				a[temp1]=1;
				
			}

			if(i==997) break;
			for(k=i+1;k<=1000;k++)
				{if (a[k]==0) {i=k;cout<<i<<" ";break;}}
	

		}

	for(int i=2;i<=1000000;i++)
	{
		if(a[i]==0) {b[count1]=i;count1++;}
	}
	cout<<b[78497]<<endl;
}