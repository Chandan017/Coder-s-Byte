class Solution {
public:
    
    int n , m , mod = 1e9+7;
    long solve(vector<vector<int>> &grid , int r , int c , int k , long sum , vector<vector<vector<int>>> &dp)
    {
        if(r>=n || c>=m)
            return 0;
        
        sum += grid[r][c];
        sum %= k;
        if(r==n-1 && c==m-1)
        {
            if((sum%k) == 0)
            {
                return 1;
            }
              
            return 0;
        }
        
        if(dp[r][c][sum] != -1)
            return dp[r][c][sum];
        
        long down = solve(grid , r+1 , c, k ,sum , dp);
        long right = solve(grid , r , c+1 , k , sum , dp);
        
        
        long total = ((down%mod) + (right%mod))%mod;
        return dp[r][c][sum] = total;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        
        
        n = grid.size() , m = grid[0].size();
        vector<vector<vector<int>>> dp(n+1 , vector<vector<int>>(m+1 , vector<int>(k+1 , -1)));
        long res = solve(grid , 0 , 0 , k , 0 , dp);
        
        return res;
    }
};