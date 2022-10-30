class Solution {
public:
    
    int minimumObstacles(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dp(n , vector<int> (m , 1e5+1));
        
        
        queue<tuple<int,int>> q;
        q.push({0,0});
        dp[0][0] = 0;
        
        int dx[] = {-1,1,0,0};
        int dy[] ={0,0,-1,1};
        
        while(q.size())
        {
            auto [x,y] = q.front();
            q.pop();
            
            
            for(int ind=0;ind<4;ind++)
            {
                int newX = x + dx[ind];
                int newY = y + dy[ind];
                
                if(newX>=0 && newX<n && newY>=0 && newY<m)
                {
                    if(dp[newX][newY] > dp[x][y] + grid[newX][newY])
                    {
                        dp[newX][newY] = dp[x][y] + grid[newX][newY];
                        q.push({newX , newY});
                    }  
                }
            }
            
            
        }
        
        return dp[n-1][m-1];
        
    }
};