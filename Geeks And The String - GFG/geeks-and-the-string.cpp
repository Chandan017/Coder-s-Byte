//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        // code here
        
        string res = "";
        
        for(auto it:s)
        {
            if(res.length() && res.back()==it)
                res.pop_back();
            else
                res += it;
        }
        
        if(res.length() == 0)
            return "-1";
        
        return res;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends