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
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='9')
            s[i]='6';
        else if(s[i]=='6')
            s[i]='9';
    }
    cout<<s<<endl;
    
    
    
    return 0;
}