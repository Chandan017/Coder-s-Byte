#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(i,a,b) for(int i=a;i<=(b);i++)
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
    bool right[n],left[n];
    for(int i=0;i<n;i++)
        cin>>left[i]>>right[i];
    ll leftZero=0,leftOne=0,rightZero=0,rightOne=0;
    for(int i=0;i<n;i++)
    {
        if(left[i]==0)
            leftZero++;
        if(right[i]==0)
            rightZero++;
        if(left[i]==1)
            leftOne++;
        if(right[i]==1)
            rightOne++;
        
    }
    cout<<(min(leftOne,leftZero) + min(rightOne,rightZero))<<endl;
        
    
    
    
    return 0;
}