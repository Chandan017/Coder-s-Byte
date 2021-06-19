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
    
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll arr[n],sum=0;
        loop(i,0,n)
        {
            cin>>arr[i];
            sum+=arr[i];
        }
        
        if(sum==n)
            cout<<0<<endl;
        else if(n+1-sum>=1)
            cout<<1<<endl;
        else    
            cout<<sum-n<<endl;
        
    }
    
    
    return 0;
}