#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
//#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <sstream>
#include <map>
#include <set>
using namespace std;

typedef long long ll;



const ll mod=1000000007ll;
const int nn=100005;
double eps=1e-8;

	
#define sc(x) scanf("%d",&(x))
#define scl(x) scanf("%lld",&x)
#define pb push_back
#define mp make_pair
#define fori(n) for(int i=1;i<=n;i++)
#define forj(n) for(int j=1;j<=n;j++)

int a[nn];
int bit[nn];



void update(int i,int val,int n)//n optional
{
	while(i<=n)
	{
		bit[i]+=val;
		i=i+(i & -i);
	}
}

int query(int i)
{	
	int sum=0;
	while(i>0)
	{
		sum+=bit[i];
		i=i-(i & -i);
	}
	return sum;
}



////************
int main()
{
	int n;
	sc(n);
	bit[0]=0;
	for(int i=1;i<=n;i++)
		sc(a[i]);
	for(int i=1;i<=n;i++)
	{
		update(i,a[i],n);//n optional
	}
	for(int i=0;i<=n;i++)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	for(int i=0;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<=n;i++)
	{
		cout<<bit[i]<<" ";
	}
	cout<<endl;
	cout<<query(3)<<endl;
	cout<<query(6)<<endl;
	update(5,1,n);
	cout<<query(6)<<endl;
	for(int i=0;i<=n;i++)
	{
		cout<<bit[i]<<" ";
	}
	cout<<endl;

	
					
}