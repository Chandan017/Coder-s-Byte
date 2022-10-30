class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dp(n , vector<int> (m , 1e5+1));
        
        
        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> q;
        q.push({0,0,0});
        
        int dx[] = {-1,1,0,0};
        int dy[] ={0,0,-1,1};
        
        while(q.size())
        {
            vector<int> curr = q.top();
            q.pop();
            
            
            if(curr[1] == n-1 && curr[2]==m-1)
                return curr[0];
            
            for(int ind=0;ind<4;ind++)
            {
                int newX = curr[1] + dx[ind];
                int newY = curr[2] + dy[ind];
                
                if(newX>=0 && newX<n && newY>=0 && newY<m)
                {
                    if(dp[newX][newY] > curr[0] + grid[newX][newY])
                    {
                        dp[newX][newY] = curr[0] + grid[newX][newY];
                        q.push({dp[newX][newY] , newX , newY});
                    }  
                }
            }
            
            
        }
        
        
        
        
        return -1;
        
    }
};