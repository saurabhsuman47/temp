#include <iostream>
using namespace std;
#include <cstring>
#include <cstdio>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <stack>
#include <queue>
#include <utility>
double eps=1e-8;

int main() 
{int t;
scanf("%d",&t);
for(int k=0;k<t;k++)
	{	
		int n,w;
		scanf("%d %d",&n,&w);
		int c[n],p[n];
		int t[n];
		double value[n];
		
		for(int j=0;j<n;j++)
			{
				scanf("%d %d %d",&c[j],&p[j],&t[j]);
				value[j]=(c[j]*p[j]*1.0)/(t[j]*1.0);
			}
			
			pair<double,int> pairs[ n ];
			
			for ( int i = 0; i < n; ++i )
			  pairs[ i ] = make_pair( value[ i ], t[ i ] );
			
			sort( pairs, pairs+n );
			
			for ( int i = 0; i < n; ++i )
			{
			  value[ i ] = pairs[ i ].first;
			  t[ i ] = pairs[ i ].second;
			}
			
			int sum=0;
			int s=0;
			int index=0;
			int ww=w;
			for(int zz=n-1;zz>=0;zz--)
			{
				if(index+t[zz]<=w)
				{sum+=value[zz]*t[zz]+eps;index+=t[zz];}
			}
			cout<<sum<<endl;
	}
	
}