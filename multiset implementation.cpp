#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


const ll mod=1000000007ll;
double eps=1e-8;
const int N=100001;

	
#define sc(x) scanf("%d",&(x))
#define scl(x) scanf("%lld",&x)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)



////************
int main()
{
	int t;
	sc(t);
	while(t--)
	{
		int n;sc(n);
		int nn=n;
		int t1=1;fori(n)t1*=2;n=t1;
		int a[n];fori(n)sc(a[i]);sort(a,a+n);

		multiset<int> MS;
		multiset<int>:: iterator it;
		MS.insert(a,a+n);
		it=MS.find(0);MS.erase(it);

		int b[nn];
		int ii=0;
		it=MS.begin();a[ii]=*it;ii++;MS.erase(it);
		fori(ii)
		{
			
		}



		for(it=MS.begin();it!=MS.end();it++)
		{
			cout<<*it<<endl;
		}
		cout<<endl;

		
	}
	
	


}