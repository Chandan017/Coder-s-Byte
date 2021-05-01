#include<bits/stdc++.h>
using namespace std;


int main(int argc, char *a[])
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,r,i,j,flag;
        vector<int> v;
        cin>>l>>r;
        
        if (l <= 2) {
        l = 2;
        if (r >= 2) {
            v.push_back(l);
            l++;
        }
    }
           

            if (l % 2 == 0)
        l++;
 
   
    for (i = l; i <= r; i = i + 2) {
 
        
        bool flag = 1;
 
        
        for (j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }
 
      
        if (flag == 1)
            v.push_back(i);
    }
    if(v.size()==0)
        cout<<-1<<endl;
    else if(v.size()==1)
        cout<<0<<endl;    
    else
        cout<<(v[v.size()-1]-v[0])<<endl;    
        
        
          v.clear();  
}

}