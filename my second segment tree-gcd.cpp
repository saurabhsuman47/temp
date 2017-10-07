#include <iostream>
using namespace std;
#include <cstring>
#include <cstdio>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <list>

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long> vl;

double eps=1e-8;
const ll mod=1000000007ll;

#define sc(x) scanf("%d",&(x))
#define scl(x) scanf("%lld",&(x))

struct node
{
	int value;
	int left;
	int right;
};
int a[100001];
node b[400010];

int gcd ( int p1, int p2 )
{
  int temp;
  while ( p1 != 0 ) {
     temp = p1; p1 = p2%p1;  p2 = temp;
  }
  return p2;
}

void build(int i,int x,int y)
{
	if(x>y)return;
	else if(x==y){b[i].value=a[x];b[i].left=x;b[i].right=y;return;}
	build( i*2+1,x,(y+x)/2);//cout<<"i "<<i<<endl;
	build(i*2+2,1+(y+x)/2,y);//cout<<"i2 "<<i<<endl;
	int pp1=b[i*2+1].value;
	int pp2=b[i*2+2].value;
	b[i].value=gcd(pp1,pp2);//cout<<"i "<<i<<endl;
	b[i].left=x;
	b[i].right=y;



}
void update(int node,int i,int nval)
{
	if(i==b[node].left && i==b[node].right){b[node].value=nval;return;}
	else
	{
		if(i>=b[node*2+1].left && i<=b[node*2+1].right)update(node*2+1,i,nval);
		if(i>=b[node*2+2].left && i<=b[node*2+2].right)update(node*2+2,i,nval);
		b[node].value=gcd(b[node*2+1].value,b[node*2+2].value);
		
	}
}

int query(int node,int i,int j)
{
	if(i>b[node].right || j<b[node].left){return 0;}
	if(i<=b[node].left && j>=b[node].right){return b[node].value;}
	else
	{
		return query(node*2+1,i,j)+query(node*2+2,i,j);
	}
}
int main()
{
	int n=100001;
	for(int i=1;i<=n;i++)
		a[i]=0;
	
	//cout<<endl;
	build(0,1,4);
	for(int i=0;i<10;i++)
	{
		cout<<b[i].value<<" | ";
	}
	cout<<endl;
	for(int i=0;i<10;i++)
	{
		cout<<b[i].left<<","<<b[i].right<<" | ";
	}
	
	
}