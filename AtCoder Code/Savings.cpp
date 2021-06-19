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
    ll count=0,sum=0,i=1;
    while(1)
    {
        if(sum<n)
        {
            count++;
            sum+=i;
            i++;
        }
        else if(sum>=n)
            break;
    }
    cout<<count<<endl;
    
    
    return 0;
}