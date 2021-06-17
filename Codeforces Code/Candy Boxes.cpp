#include<cstdio>
#include<cmath>
#include<algorithm>
#define N 100010
using namespace std;
int n,a[N],i;
int main()
{
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    scanf("%d",&a[i]);
    if (n==0)
    {
        printf("YES\n1\n1\n3\n3\n");
    }
    else
    if (n==1)
    {
        printf("YES\n");
        printf("%d\n%d\n%d\n",2*a[1],2*a[1],3*a[1]);
    }
    else
    if (n==2)
    {
        int z,j;
        sort(a+1,a+3);
        for (i=a[2];i<=100000;i++)
        {
            z=i-a[1];
            j=z*4-a[1]-a[2]-i;
            if ((j>=a[1])&&(j<=i))
            if (((j+a[2])*1.0)/2==z)
            {
                printf("YES\n%d\n%d\n",i,j);
                return 0;   
            }
        }
        printf("NO");
    }
    else
    if (n==3)
    {
        int mi,ma,sum,mid;
        for (i=1;i<=100000;i++)
        {
            mi=min(min(i,a[1]),min(a[2],a[3]));
            ma=max(max(i,a[1]),max(a[2],a[3]));
            sum=i+a[1]+a[2]+a[3];
            mid=(sum-mi-ma)*2;
            ma=(ma-mi)*4;
            if ((sum==mid)&&(sum==ma))
            {
                printf("YES\n");
                printf("%d\n",i);
                return 0;
            }
        }
        printf("NO");
    }
    else
    {
        int o,p,q; 
        sort(a+1,a+5);
        o=(a[4]-a[1])*4;
        p=(a[1]+a[2]+a[3]+a[4]);
        q=(a[2]+a[3])*2;
        if ((o==p)&&(o==q))
        printf("YES");
        else
        printf("NO");
    }
}