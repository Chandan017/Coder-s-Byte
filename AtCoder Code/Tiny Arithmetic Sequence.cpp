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
    ll arr[3];
    loop(i,0,3)
        cin>>arr[i];
    sort(arr,arr+3);
    ll d1=abs(arr[0]-arr[1]);
    ll d2=abs(arr[1]-arr[2]);
    if(d1==d2)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
        
    return 0;
}