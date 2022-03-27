class Solution {
public:
    
    int n;
    int dp[101][101];
    
    long getPath(vector<vector<int>> &matrix , int r , int c )
    {
        if(r<0 || c<0 || r>=n || c>=n)
            return INT_MAX;
        
        
        if(r==n-1)
            return matrix[r][c];
        
        if(dp[r][c])
            return dp[r][c];
        
        int leftDiagonal=getPath(matrix , r+1 , c-1);
        int rightDiagonal=getPath(matrix , r+1 , c+1 );
        int down=getPath(matrix , r+1 , c);
        
        long ans = matrix[r][c] + min(leftDiagonal , min(rightDiagonal , down));
        
        return dp[r][c]= ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        n=matrix.size();
        
        int minFallingPath=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int currFallingPath = getPath(matrix , 0 , i);
            
            minFallingPath = min(currFallingPath , minFallingPath);
        }
        
        return minFallingPath;
        
    }
};