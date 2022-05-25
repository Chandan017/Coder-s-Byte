class Solution {

private:
    int n , m;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    
    int solve(vector<vector<int>> &matrix , int r , int c , vector<vector<int>> &dp)
    {
        
        if(dp[r][c])
            return dp[r][c];
        
        int maxPath = 1;
        for(int ind=0;ind<4;ind++)
        {
            int newR = r+dx[ind];
            int newC = c+dy[ind];
            
            if(newR>=0 && newC>=0 && newR<n && newC<m && matrix[newR][newC] > matrix[r][c])
            {
                int currPath = 1 + solve(matrix , newR , newC , dp);
                maxPath = max(maxPath , currPath);
            }
        }
        
        return dp[r][c] = maxPath;
    }
public:
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        n = matrix.size() , m= matrix[0].size();
        vector<vector<int>> dp(n+1 , vector<int> (m+1));
        int maxPath = 1;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int currPath = solve(matrix , i , j , dp);
                
                maxPath = max(maxPath , currPath);
            }
        }
        
        
        
        return maxPath;
        
    }
};