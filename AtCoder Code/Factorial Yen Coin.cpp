#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(i,a,b) for(int i=a;i<(b);i++)
#define ff first
#define ss second
#define vi vector<int>
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main()
{
    fastio();
    
    ll  p;
    cin>>p;
    ll p1=1,p2=2,p3=6,p4=24,p5=120,p6=720,p7=5040,p8=40320,p9=362880,p10=3628800;
    ll ans=0;
    ans+=p/p10;
    p=p%p10;
    ans+=p/p9;
    p=p%p9;
     ans+=p/p8;
    p=p%p8;
     ans+=p/p7;
    p=p%p7;
     ans+=p/p6;
    p=p%p6;
     ans+=p/p5;
    p=p%p5;
     ans+=p/p4;
    p=p%p4;
     ans+=p/p3;
    p=p%p3;
     ans+=p/p2;
    p=p%p2;
     ans+=p/p1;
    p=p%p1;
    cout<<ans<<endl;
    
    return 0;
}