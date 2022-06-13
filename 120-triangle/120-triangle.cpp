class Solution {
public:
    int n ;
    int cnt = 0;
    int minPathSum(vector<vector<int>> &triangle , int r , int c , vector<vector<int>> &dp)
    {
        
        if(dp[r][c] != INT_MAX)
            return dp[r][c];
        
        if(r==n-1)
        {
            return triangle[r][c];
        }        
        
        int i_index = triangle[r][c] +  minPathSum(triangle , r+1 , c , dp);
        int i_plus_one_index = triangle[r][c] + minPathSum(triangle , r+1 , c+1 ,dp);
        
        return  dp[r][c] =min(i_index , i_plus_one_index);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        n = triangle.size();
        
        vector<vector<int>> dp(n , vector<int>(n , INT_MAX));
        int minPath = minPathSum(triangle , 0 , 0 , dp);
        
        return minPath;
        
    }
};