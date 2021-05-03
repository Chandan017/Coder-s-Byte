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
    ll arr[n-1],actualSum=0;
    loop(i,0,n-1)
    {
        cin>>arr[i];
        actualSum +=arr[i];
    }
    
    ll expectedSum = (n*(n+1))/2;
    cout<<(expectedSum-actualSum)<<endl;
    
    
    return 0;
}