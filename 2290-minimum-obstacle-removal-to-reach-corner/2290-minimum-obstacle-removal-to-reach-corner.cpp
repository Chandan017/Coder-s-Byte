class Solution {
public:
    
    int minimumObstacles(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dp(n , vector<int> (m , 1e5+1));
        
        
        priority_queue<tuple<int,int,int> , vector<tuple<int,int,int>> , greater<tuple<int,int,int>>> q;
        q.push({0,0,0});
        
        int dx[] = {-1,1,0,0};
        int dy[] ={0,0,-1,1};
        
        while(q.size())
        {
            auto [cnt,x,y] = q.top();
            q.pop();
            
            
            if(x == n-1 && y==m-1)
                return cnt;
            
            for(int ind=0;ind<4;ind++)
            {
                int newX = x + dx[ind];
                int newY = y + dy[ind];
                
                if(newX>=0 && newX<n && newY>=0 && newY<m)
                {
                    if(dp[newX][newY] > cnt + grid[newX][newY])
                    {
                        dp[newX][newY] = cnt + grid[newX][newY];
                        q.push({dp[newX][newY] , newX , newY});
                    }  
                }
            }
            
            
        }
        
        
        
        
        return -1;
        
    }
};