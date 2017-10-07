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

vector<int> adj[10001];
bool vis[10001];
int d[10001];
void bfs(int s)
{
	for(int i=0;i<10001;i++)
	{
		vis[i]=0;
		d[i]=10010;
	}
	vis[s]=1;
	d[s]=0;
	queue<int> myqueue;
	myqueue.push(s);
	while(!myqueue.empty())
	{
		int t1=myqueue.front();
		
		for(int u=0;u<adj[t1].size();u++)
		{	int v=adj[t1][u];
			if(vis[v]==0)
			{
				myqueue.push(v);
				vis[v]=1;
				d[v]=d[t1]+1;
			}
		}
		myqueue.pop();
	}
}


int main() 
{	
	int n;
	sc(n);
	int zz;
	for(int i=0;i<n-1;i++)
	{
		int t1,t2;
		sc(t1);if(i==0)zz=t1;
		sc(t2);
		adj[t1].push_back(t2);
		adj[t2].push_back(t1);
	}
	if(n==0 || n==1)cout<<"0"<<endl;
	
	//cout<<adj[1][0]<<" | "<<adj[1][1]<<" | "<<adj[2][0]<<" | "<<adj[2][1]<<" | "<<adj[2][2]<<endl;
	else{
		bfs(zz);
		//cout<<d[0]<<" | "<<d[1]<<" | "<<d[2]<<" | "<<d[3]<<endl;
		int maxdist=-1;
		int imaxdist=0;
		for(int i=1;i<=n;i++)
		{
			if(d[i]>maxdist){maxdist=d[i];imaxdist=i;}
		}
		//cout<<maxdist<<" | "<<imaxdist<<endl;
		bfs(imaxdist);
		maxdist=-1;
		for(int i=1;i<=n;i++)
		{
			if(d[i]>maxdist)maxdist=d[i];
		}
		cout<<maxdist<<endl;
	}
	
}