class Solution {
public:
    int n;
    
    int dp[102][102];
    
    long getPathSum(vector<vector<int>> &matrix , int r , int c )
    {
        if(r<0 || c<0 || r>=n || c>=n)
            return INT_MAX;
        if(r==n-1)
            return matrix[r][c];
        
        if(dp[r][c])
            return dp[r][c];
        
        int leftDiagonal = getPathSum(matrix , r+1 , c-1);
        int rightDiagonal = getPathSum(matrix , r+1 , c+1);
        int down = getPathSum(matrix , r+1 , c);
        
        int currPathSum = matrix[r][c] + min({leftDiagonal , rightDiagonal , down});
        
        return dp[r][c] = currPathSum;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        n = matrix.size();
        
        int minPathSum = INT_MAX;
        for(int i=0;i<n;i++)
        {
            int currFallingPathSum = getPathSum(matrix , 0 , i );
            minPathSum = min(minPathSum , currFallingPathSum);
        }
        
        return minPathSum;
        
    }
};