#include<cstdio>
using namespace std;
int n,k,i,j;
int main()
{
  scanf("%d%d",&n,&k);
  for (i=1;i<=n;i++)
  {
    for (j=1;j<=n;j++)
      if (j==i) printf("%d ",k);else printf("0 ");
    puts("");
  }
  return 0;
}
