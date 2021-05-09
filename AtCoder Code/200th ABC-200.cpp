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
    ll n,k;
    cin>>n>>k;
    while(k--)
    {
        if(n%200==0)
            n=n/200;
        else
        {
            string s = to_string(n);
            s+="200";
            n = stoll(s);
        }
        
    }
    
    cout<<n<<endl;
    
    
    
    return 0;
}