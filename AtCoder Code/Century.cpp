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
    if(n<=100)
        cout<<1<<endl;
    else
    {
        ll x = n/100;
        if(x*100!=n)
            x=x+1;
        cout<<x<<endl;    
        
        
    }
    
    
    
    return 0;
}