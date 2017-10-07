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


int main() 
{	
	int t;
	scanf("%d",&t);
	map <string,int> mymap;
	for(int pp=0;pp<t;pp++)
	{
		string s;
		cin>>s;
		if(mymap.find(s)==mymap.end()){mymap[s]=1;printf("%s\n","OK");}
		else
		{
			int t1=mymap[s];
			printf("%s",s);
			printf("%d\n",t1);
			mymap[s]+=1;
		}


	}
	
}