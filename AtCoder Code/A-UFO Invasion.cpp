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
   string s;
   cin>>s;
   int count =0;
   for(int i=0;i<(s.length()-3);i++)
   {
       if(s[i]=='Z'  && s[i+1]=='O' && s[i+2]=='N' && s[i+3]=='e'){
        count++;
       }
      
   }
   cout<<count<<endl;
    
    
    
    return 0;
}