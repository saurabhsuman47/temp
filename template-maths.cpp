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
typedef vector<int> vi;
const ll mod=1000000007ll;
#define sc(x) scanf("%d",&(x))
#define scl(x) scanf("%lld",&(x))
ll gcd(ll a,ll b) 
{if(b==0) return a; 
else {
	
	return gcd(b,a%b);
}
}
ll exp(ll a,ll b)
{
	ll result=1;
	while(b!=0)
	
	{	if(b%2==1)result*=a;
		
		a*=a;
		b/=2;
	}
	return result;
}


int main() 
{	ll t=exp(2,50);
	cout<<t<<endl;
	
	
	
}