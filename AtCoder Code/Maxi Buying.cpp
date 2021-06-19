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
    ll ans=1.08*n;
    if(ans<206)
        cout<<"Yay!"<<endl;
    else if(ans==206)
        cout<<"so-so"<<endl;
    else
        cout<<":("<<endl;
    
    return 0;
}