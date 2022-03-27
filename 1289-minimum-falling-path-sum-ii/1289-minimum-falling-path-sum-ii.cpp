class Solution {
public:
    
    int n;
    int dp[201][201];
    
    int getPath(vector<vector<int>> &grid , int r, int c)
    {
        if(r<0 || c<0 || r>=n || c>=n)
            return INT_MAX;
        
        if(r==n-1)
            return grid[r][c];
        
        if(dp[r][c])
            return dp[r][c];
        
        long minPath=INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            if(i!=c)
            {
                long currPath = getPath(grid , r+1 ,i);
                
                minPath = min(currPath , minPath);
            }
        }
        
        return dp[r][c] = (grid[r][c] + minPath);
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        
        n=grid.size();
        
        int minPath = INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            int currPath = getPath(grid , 0 , i);
            
            minPath = min(minPath , currPath);
        }
        
        return minPath;
        
    }
};