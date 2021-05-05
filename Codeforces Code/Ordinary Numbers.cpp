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
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        if(n<=9)
            cout<<n<<endl;
        else if(n==10)
            cout<<n-1<<endl;
        else
        {
            ll count =9;
            for(int i=11;i<=n;i++)
            {
            
                string s = to_string(i);
                bool flag=false;
                for(int i=0;i<s.length()-1;i++)
                {
                    if(s[i]!=s[i+1])
                    {
                        flag=true;
                        break;
                    }
                }
                if(flag==false)
                    count++;
                
            }
            cout<<count<<endl;
            
        }
        
        
    }
    
    
    
    return 0;
}