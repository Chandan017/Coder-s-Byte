#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(i,a,b) for(int i=a;i<(b);i++)
#define ff first
#define ss second
#define vi vector<int>


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    vector<int> a(n),b(n),c(n),v(n);
    for(auto& i:a)
    {
        cin>>i;
        i-=1;
    }
    for(auto& i:b)
    {
        cin>>i;
        i-=1;
    }
    for(auto& i:c)
    {
        cin>>i;
        i-=1;
    }
    
    for(int i=0;i<n;++i)
    {
        v[b[c[i]]]+=1;
    }
    ll ans=0;
    for(int i=0;i<n;++i)
    {
        ans+=v[a[i]];
    }
    cout<<ans<<endl;
    
    
    return 0;
}