#include <iostream>
using namespace std;
#include <stdio.h>
void quicksort(int*,int ,int);
int partition(int* ,int ,int );
void swap(int *a,int *b);

int main()
{
    int t;
    scanf("%d",&t);
    int a[t];
    for(int i=0;i<t;i++)
    {  scanf("%d",&a[i]);}
    quicksort(a,0,t-1);
    for (int i=0;i<t;i++)
    {printf("%d \n",a[i]);}
    return 0;
}
void quicksort(int *a,int p,int r)
{
     int q;
     if (p<r)
	{ q= partition(a,p,r);
	quicksort(a,p,q-1);
	quicksort(a,q+1,r);}
}
int partition(int *a,int p,int r)
{int x=a[r];
int i=p-1;
	for(int k=p;k<r;k++)
	{
		if(a[k]<=x)
		{i++;
		swap(a+k,a+i);}
	}
	swap(a+r,a+i+1);
	return i+1;
}
void swap(int *a,int *b)
{int temp;
				temp=*a;
				*a=*b;
				*b=temp;}
