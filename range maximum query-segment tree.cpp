#include <bits/stdc++.h>
using namespace std;
struct seg{
	int val;
	int ind;
};

int A[10]={1,20,37,48,5,69,7,81,9,0};
int M[4000];
void initialize(int node, int b, int e){
	if (b == e){
		M[node] = A[b];		
	}   
	else{

		initialize(2 * node, b, (b + e) / 2);
		initialize(2 * node + 1, (b + e) / 2 + 1, e);

		if (M[2 * node] >= M[2 * node + 1]){
			M[node]= M[2 * node];
		}
		else{
			M[node]= M[2 * node + 1]; 
		}
	}
} 

seg* query(int node,int b,int e,int i, int j){
	seg *p1, *p2;

	if (i > e || j < b)return -1;

	if (b >= i && e <= j){
		return M[node];
	}
	
	p1 = query(2 * node, b, (b + e) / 2, i, j);
	p2 = query(2 * node + 1, (b + e) / 2 + 1, e, i, j);


	if (p1 == -1)return p2;
	if (p2 == -1)return p1;
	if (p1 >= p2)return p1;
	else return p2;
	
}

 int main(){
	initialize(1,0,9);
	cout<<M[1].val<<endl;
	cout<<M[1].ind<<endl;
	int q1=query(1,0,9,1,6);
	cout<<q1<<endl;
	
 }
