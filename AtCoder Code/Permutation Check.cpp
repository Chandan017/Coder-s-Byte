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
    
    ll n;
    cin>>n;
    unordered_set<ll> s;
    bool flag=true;
    loop(i,0,n)
    {
        ll x;
        cin>>x;
        if(x<=n && x>=1)
            s.insert(x);
        else if(x>n)
            flag=false;
    }
    if(flag && s.size()==n)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    
    return 0;
}