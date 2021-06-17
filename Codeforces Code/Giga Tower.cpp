#include<cstdio>
#include<cmath>
using namespace std;
int check(int x)
{
    if (x<0) x=-x;
    while (x)
    {
        if (x%10==8) return 1;
        x=x/10;
    }
    return 0;
}
int abs(int x)
{
    if (x<0) x=-x;return x;
}
int min(int a,int b)
{
    if (a<b) return a;return b;
}
int main()
{
    int n,i,ans=0x37373737;
    scanf("%d",&n);
    for (i=1;i<=100;i++)
    if (check(n+i))
    ans=min(ans,abs(i));
    printf("%d",ans);
}