//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    int mod = 1e9+7;
    
    int solve(vector<vector<int>> &grid , int r , int c , vector<vector<int>> &dp)
    {
        if(r<0 || c<0 || grid[r][c] == 0)
            return 0;
            
        if(r==0 && c== 0)
            return 1;
            
        if(dp[r][c] != -1)
            return dp[r][c];
            
        int up = solve(grid , r-1 , c , dp)%mod;
        int left = solve(grid , r , c-1 , dp)%mod;
        
        dp[r][c] = (up+left)%mod;
        
        return dp[r][c];
    }
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        // code here
        
        if(grid[0][0]==0 || grid[n-1][m-1]==0)
            return 0;
        vector<vector<int>> dp(n+1 , vector<int>(m+1 , -1));
        int res = solve(grid , n-1 , m-1 , dp);
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends