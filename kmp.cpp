#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
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
double eps=1e-8;

    
#define sc(x) scanf("%d",&(x))
#define scl(x) scanf("%lld",&x)
#define pb push_back
#define mp make_pair
#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)

string pattern;string target;
void preKMP(int idx, int f[])

{
    int m = idx+1;int k;

    
    f[0] = -1;
    for (int i = 1; i < m; i++)
    {
        k = f[i - 1];
        while (k >= 0)
        {
            if (pattern[k] == pattern[i - 1])
                break;
            else
                k = f[k];
        }
        f[i] = k + 1;
    }
}

 

//check whether target string contains pattern 

int kmp(int idx)

{
    int m = idx+1;
    int n = target.length();
    int f[n]; 
    preKMP(idx,f);     

    int i = 0;
    int k = 0;
    while (i < n)
    {
        if (k == -1)
        {
            i++;
            k = 0;
        }
        else if (target[i] == pattern[k])
        {
            i++;
            k++;
            if (k == m)
                return i-m;
        }
        else
            k = f[k];
    }
    return -1;
}



////************
int main()
{
    int n;sc(n);
    cin>>pattern;
    cin>>target;
    target+=target;
    //cout<<target<<endl;
    int start=0;int end=n-1;
    int sol=-1;
    int temp=-5;
    int mid=(start+end)/2;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(mid==temp)break;
        temp=mid;
        int t1=kmp(mid);
        //cout<<t1<<endl;
        if(t1>=0){sol=t1;start=mid;}
        else{end=mid;}
        //cout<<start<<" "<<end<<endl;

    }
    cout<<sol<<endl;

}