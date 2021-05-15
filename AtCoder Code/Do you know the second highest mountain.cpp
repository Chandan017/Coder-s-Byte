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
    ll n,height;
    cin>>n;
    string name;
    priority_queue<pair<int,string>> pq;
    for(int i=0;i<n;i++)
    {
        cin>>name>>height;
        pq.push(make_pair(height,name));
    }
    pq.pop();
    cout<<pq.top().second<<endl;
    
    
    
    return 0;
}