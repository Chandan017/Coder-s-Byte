#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll a,b,c;
    cin>>a>>b>>c;
    ll sq= (a*a) + (b*b);
    c=c*c;
    if(sq<c)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    
    
    
    return 0;
}