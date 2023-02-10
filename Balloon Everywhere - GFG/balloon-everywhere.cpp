//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        
        map<char,int> mpp;
        
        for(auto it:s)
            mpp[it]++;
        int res = INT_MAX;
        string balloon = "balon";
        
        
        
        for(auto it:balloon)
        { 
            if(mpp.find(it) == mpp.end())
                return 0;
                
            if(it == 'o' || it=='l')
            {
                res = min(res , mpp[it]/2);
            }
            else
                res = min(res , mpp[it]);
        }
        
        return res;
        
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends