#include  <cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL long long 
int n;
int last[100009],p[100009];
int main()
{
	scanf("%d",&n);int x;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(last[x]==0)last[x]=i;
		else if(last[x]>0)
		{
			if(p[x]==0)p[x]=i-last[x],last[x]=i;
			else if(p[x]==i-last[x])last[x]=i;
			else last[x]=-1;
		}
	}
	int sum=0;
	for(int i=1;i<=100000;i++)
		if(last[i]>0)sum++;
	printf("%d\n",sum);
	for(int i=1;i<=100000;i++)if(last[i]>0)
		printf("%d %d\n",i,p[i]);
}