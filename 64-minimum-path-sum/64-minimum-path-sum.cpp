class Solution {
public:
    int n , m;
    
    int solve(vector<vector<int>> &grid , int r , int c , vector<vector<int>> &dp)
    {
        
        if(r<0 || r>=n || c>=m || c<0)
            return INT_MAX;
        
        if(dp[r][c])
            return dp[r][c];
        
        if(r==n-1 && c==m-1)
        {
            return grid[r][c];
        }
        
        int currSum = grid[r][c];
    
        int down = solve(grid , r+1 , c , dp);
        int right = solve(grid , r , c+1, dp);
        
        
        currSum += min(down , right);
        
        return dp[r][c] = currSum;
        
    }
    int minPathSum(vector<vector<int>>& grid) {
        
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> dp(n+1 , vector<int>(m+1));
        int minSum = solve(grid , 0 , 0 , dp);
        
        return minSum;
        
    }
};