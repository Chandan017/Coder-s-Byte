class Solution {
public:
    
   
    int n , m;
    int dp[101][101][202];	
    bool check(vector<vector<char>> &grid , int r , int c , int sum)
    {
        if(r>=n || c>=m )
            return false;
      
        if(grid[r][c] == ')' && sum == 0)
            return false;
        
        if(grid[r][c] == '(')
            sum++;
        else
            sum--;
        if(r==n-1 && c==m-1)
        {
            cout<<sum<<endl;
            return (sum==0);
        }
        
        if(dp[r][c][sum] != -1)
            return dp[r][c][sum];
        
        bool down = check(grid , r+1 , c, sum);
        bool right = check(grid , r , c+1 , sum);
        
        return dp[r][c][sum] = (down || right);
        
        
    }
    
    bool hasValidPath(vector<vector<char>>& grid) {
        
        
        n = grid.size() , m = grid[0].size();
         memset(dp, -1, sizeof(dp));
        
        bool ans = check(grid , 0 , 0 , 0);
        
        return ans;
        
       
        
    }
};