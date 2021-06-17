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
    
    ll a,b,c;
    cin>>a>>b>>c;
    if(a>0 && b>0)
    {
        if(a>b) 
            cout<<'>'<<endl;
        else if(a==b)
            cout<<'='<<endl;
        else
            cout<<'<'<<endl;
    }
    else if(a<0 && b>0)
    {
        if(c%2==0)
        {
            if(abs(a)>b)
                cout<<'>'<<endl;
            else if(abs(a)==b)
                cout<<'='<<endl;
            else
                cout<<'<'<<endl;
        }
        else if(c%2!=0)
            cout<<'<'<<endl;
    }
    
    else if(a>0 && b<0)
    {
        if(c%2==0)
        {
            if(a>abs(b))
                cout<<'>'<<endl;
            else if(a==abs(b))
                cout<<'='<<endl;
            else
                cout<<'<'<<endl;
        }
        else if(c%2!=0)
            cout<<'>'<<endl;
    }
    else if(a<0 && b<0)
    {
        if(c%2==0)
        {
            if(abs(a)>abs(b))
                cout<<'>'<<endl;
            else if(abs(a)==abs(b))
                cout<<'='<<endl;
            else 
                cout<<'<'<<endl;
        }
        else if(c%2!=0)
        {
            if(a>b)
                cout<<'>'<<endl;
            else if(a==b)
                cout<<'='<<endl;
            else 
                cout<<'<'<<endl;
        }
    }
    else if(a==0 || b==0)
    {
       if(c%2==0)
       {
           if(a==0 && b==0)
                cout<<'='<<endl;
            else if(a==0 && b!=0)
                cout<<'<'<<endl;
            else    
                cout<<'>'<<endl;
       }
       else if(c%2!=0)
       {
        if(a>b)
            cout<<'>'<<endl;
        else if(a==b)
            cout<<'='<<endl;
        else
            cout<<'<'<<endl;
       }
      
    }
    return 0;
}