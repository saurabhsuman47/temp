#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

const ll mod=1000000007ll;
double eps=1e-8;
const int N=100001;
const int inf=1000000009;

	
#define sc(x) scanf("%d",&(x))
#define scl(x) scanf("%lld",&x)
#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)

int a[N];
int tree[4*N];
int lazy[4*N];

void build(int node,int start,int end){
	if(start==end){
		tree[node]=a[start];
	}
	else{
		int mid=(start+end)/2;
		build(node*2,start,mid);
		build(node*2+1,mid+1,end);
		tree[node]=tree[node*2]+tree[node*2+1];
	}
}

void rangeUpdate(int node, int start, int end, int left, int right, int val){
	if(lazy[node]!=0){
		tree[node]+=(end-start+1)*lazy[node];
		if(start!=end){
			lazy[node*2]+=lazy[node];
			lazy[node*2+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(start>end || left>end || right<start){return;}
	if(left<=start && right>=end){
		tree[node]+=(end-start+1)*val;
		if(start!=end){
			lazy[node*2]+=val;
			lazy[node*2+1]+=val;
		}
		return;
	}
	int mid=(start+end)/2;
	rangeUpdate(node*2,start,mid,left,right,val);
	rangeUpdate(node*2+1,mid+1,end,left,right,val);
	tree[node]=tree[node*2]+tree[node*2+1];
}

int rangeQuery(int node,int start, int end, int left, int right){
	if(start>end || left>end || right<start)return 0;
	if(lazy[node]!=0){
		tree[node]+=(end-start+1)*lazy[node];
		if(start!=end){
			lazy[node*2]+=lazy[node];
			lazy[node*2+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(left<=start && right>=end){
		return tree[node];
	}
	int mid=(start+end)/2;
	int q1=rangeQuery(node*2,start,mid,left,right);
	int q2=rangeQuery(node*2+1,mid+1,end,left,right);
	return q1+q2;
}


////************
int main()
{
	freopen("input.txt","r",stdin);
	int n;
	sc(n);
	fori(n){sc(a[i]);}
	build(1,0,n-1);
	for(int i=1;i<2*n;i++)cout<<tree[i]<<" ";cout<<endl;
	rangeUpdate(1,0,n-1,0,n-2,1);
	for(int i=1;i<2*n;i++)cout<<tree[i]<<" ";cout<<endl;
	cout<<rangeQuery(1,0,n-1,0,n-4)<<endl;
	for(int i=1;i<2*n;i++)cout<<tree[i]<<" ";cout<<endl;


}