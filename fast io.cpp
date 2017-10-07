#include <bits/stdc++.h>
using namespace std;

const int N=5002;

int a[N*N];

#define inchar          getchar_unlocked

inline int inPos(){

	int n = 0;
	register int ch = inchar();
	while (ch < '0' || ch > '9') ch = inchar();

	while (ch >= '0' && ch <= '9'){
		n = (n << 3) + (n << 1) + (ch - '0');
		ch = inchar();
	}
	return n;
}


////************
int main()
{
	// freopen("input.txt","w",stdout);
	
	// for(int i=0;i<N*N;i++)printf("%d ",i);
	freopen("input.txt","r",stdin);
	for(int i=0;i<N*N;i++){a[i]=inPos();}
	
	
	
	


}