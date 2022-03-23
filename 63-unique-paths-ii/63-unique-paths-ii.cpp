class Solution {
public:
    
    int dp[101][101];
    int getAll(vector<vector<int>>& obstacleGrid , int r , int c , int n,int m)
    {
        if(r>=n || c>=m || obstacleGrid[r][c]==1)
            return 0;
        
        if(r==n-1 && c==m-1)
            return 1;
        
        if(dp[r][c])
            return dp[r][c];
        int right=getAll(obstacleGrid , r , c+1 , n,m);
        int down=getAll(obstacleGrid , r+1 , c , n , m);
        
        return  dp[r][c]=down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        
        int totalPaths=getAll(obstacleGrid , 0 ,0 , n, m);
        
        return totalPaths;
    }
};