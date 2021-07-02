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
    ll count=0,magnet,nextMagnet;
    cin>>magnet;
    n--;
    while(n--)
    {
        cin>>nextMagnet;
        if(magnet!=nextMagnet)
            count++;
        magnet=nextMagnet;    
            
    }
    cout<<count+1<<endl;
    
    return 0;
}