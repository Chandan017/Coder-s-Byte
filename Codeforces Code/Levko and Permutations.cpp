#include<cstdio>
using namespace std;
int n,k,i,j,a[100005];
int main()
{
  scanf("%d%d",&n,&k);
  if (k==n) {puts("-1");return 0;}
  for (i=n-k+1;i<=n;i++)
    a[i]=i;
  for (i=1;i<n-k;i++)
    a[i]=i+1;
  a[n-k]=1;
  for (i=1;i<=n;i++) printf("%d ",a[i]);
  return 0;
}
