#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


const ll mod=1000000007ll;
double eps=1e-8;
const int N=11;

	
#define sc(x) scanf("%d",&(x))
#define scl(x) scanf("%lld",&x)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)

vector<int> adj[N];
stack<int> mystack;
stack<int> copyStack;
int recStack[N];
int vis[N];

void printCycle(int i){
	while(mystack.top()!=i){
		copyStack.push(mystack.top());
		mystack.pop();
	}
	copyStack.push(mystack.top());
	mystack.pop();
	while(!copyStack.empty()){
		cout<<copyStack.top()<<" -> ";
		mystack.push(copyStack.top());
		copyStack.pop();
	}
	cout<<endl;
}

void dfs(int i){
	vis[i]=1;
	mystack.push(i);
	recStack[i]=1;
	for(int j=0;j<adj[i].size();j++){
		int t1=adj[i][j];
		if(!vis[t1]){dfs(t1);}
		else if(recStack[t1]==1){cout<<"cycle exists"<<endl;printCycle(t1);}
	}
	mystack.pop();
	recStack[i]=0;
}

////************
int main()
{
	freopen("input.txt","r",stdin);
	int n;
	sc(n);
	int t1;int t2;
	for(int i=0;i<n;i++){
		sc(t1);sc(t2);
		adj[t1].push_back(t2);
	}

	dfs(1);
	
	


}