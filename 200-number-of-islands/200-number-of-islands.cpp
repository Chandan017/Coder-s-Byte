class Solution {
public:
    
    int n , m;
    
    void floodFill(vector<vector<char>> &grid , int r, int c)
    {
        queue<pair<int,int>> q;
        
        q.push({r,c});
        grid[r][c] = '0';
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        while(!q.empty())
        {
            int x = q.front().first ;
            int y = q.front().second;
        
            q.pop();
            
            for(int ind =0;ind<4;ind++)
            {
                int newX = x+dx[ind];
                int newY = y+dy[ind];
                
                if(newX>=0 && newY>=0 && newX<n && newY<m && grid[newX][newY]=='1')
                {
                    q.push({newX , newY});
                    grid[newX][newY] = '0';
                }
            }
        }
        
        return ;
    }
    int numIslands(vector<vector<char>>& grid) {
        
        n = grid.size();
        m = grid[0].size();
        int cnt = 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    floodFill(grid , i , j);
                    cnt++;
                }
            }
        }
        
        return cnt;
        
    }
};