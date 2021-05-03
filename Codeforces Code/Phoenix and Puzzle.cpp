#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(i,a,b) for(int i=a;i<(b);i++)
#define ff first
#define ss second
#define vi vector<int>

bool isSquare(ll n)
{
    ll a = sqrt(n);
    return (a*a==n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        if(n%2==0 && isSquare(n/2))
            cout<<"YES"<<endl;
        else if(n%4==0 && isSquare(n/4))
            cout<<"YES"<<endl;
        else 
            cout<<"NO"<<endl;
        
        
    }
    
    
    
    return 0;
}