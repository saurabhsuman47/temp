#include <bits/stdc++.h>
using namespace std;

double eps=1e-8;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
const ll mod=1000000007ll;
#define sc(x) scanf("%d",&(x))
#define scl(x) scanf("%lld",&(x))

struct node
{
	int left;int right;int value;
};

node a[100000];

void build(int n){	

    for(int i=n-2;i>=0;i--){
    	a[i].value=a[2*i+1].value+a[2*i+2].value;
    	a[i].left=min(a[2*i+1].left,a[2*i+2].left);
    	a[i].right=max(a[2*i+1].right,a[2*i+2].right);
    }              
}

int query(int nc,int l,int r){
	
	if(a[nc].left>=l && a[nc].right<=r)return a[nc].value;
	if(a[nc].left>r || a[nc].right<l)return 0;
	else{
		return query(nc*2+1,l,r)+query(nc*2+2,l,r);		
	}
}

//segment tree with min max storage
// a iterative way to build tree- tree itself contains the initial array, no need for a new array
// fill the tree from n-1 to 2*n-1 (ie n elements)
// fill the remaining by using tree[idx]=tree[idx*2+1]+tree[idx*2+2];(0 based indexing)


int main() 
{	
	int n;
	sc(n);
	
	for(int i=0;i<2*n;i++){
		a[i].value=0;

	}
	for(int i=n-1;i<2*n-1;i++){
		sc(a[i].value);
		a[i].left=i-n+2;
		a[i].right=i-n+2;
	}
	
	build(n);
	
	// for(int i=0;i<2*n-1;i++){
	// 	cout<<a[i].value<<" | ";		
	// 	cout<<a[i].left<<","<<a[i].right<<" ";
	// 	cout<<endl;
	// }

	cout<<query(0,2,3)<<endl;

	
}
