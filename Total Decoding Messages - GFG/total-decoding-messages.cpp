//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    
	    int mod = 1e9 + 7;
	    int n;
	    long solve(string &s , int ind , vector<int> &dp)
	    {
	        if(ind >= n)
	            return 1;
	        if(ind < n && s[ind] == '0')
	            return 0;
	        
	        if(dp[ind] != -1)
	            return dp[ind];
	            
	        long totalWays = solve(s , ind+1 , dp);
	        
	        if(ind+1 < n && ((s[ind] == '1' && s[ind+1] <='9') || (s[ind] == '2' && s[ind+1] <= '6')))
	            totalWays += solve(s , ind+2 , dp);
	        
	        totalWays %= mod;
	        
	        dp[ind] = totalWays;
	        return totalWays;
	    }
		int CountWays(string s){
		    // Code here
		    n = s.length();
		    vector<int> dp(n+1 , -1);
		    int res = solve(s , 0 , dp);
		    
		    return res;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends