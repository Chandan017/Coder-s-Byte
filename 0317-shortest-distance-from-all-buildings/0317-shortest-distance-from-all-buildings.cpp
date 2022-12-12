class Solution {
public:
    
    int n , m;

    int checkDist(vector<vector<int>> &grid , int r , int c , int &totalBuildings)
    {
        queue<pair<int,int>> q;
        q.push({r,c});
        vector<vector<bool>> vis(n , vector<bool>(m,false));
        vis[r][c] = true;
        
        int steps = 0 , totalDist = 0 , reachedHouses = 0;
        
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        
        while(q.size())
        {
            int len = q.size();
            while(len--)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                if(grid[x][y] == 1)
                {
                    totalDist += steps;
                    reachedHouses++;
                    continue;
                }
                
                for(int ind=0;ind<4;ind++)
                {
                    int newR = x + dx[ind];
                    int newC = y + dy[ind];
                    
                    if(newR>=0 && newC>=0 && newR<n && newC<m && !vis[newR][newC] && grid[newR][newC] != 2)
                    {
                        vis[newR][newC] = true;
                        q.push({newR , newC});
                    }
                }
            }
            steps++;
        }
        
        if(reachedHouses != totalBuildings)
        {
            
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(vis[i][j] && grid[i][j]==0)
                        grid[i][j] = 2;
                }
            }
            
            return INT_MAX;
        }
        
        return totalDist;
    }
    
    int shortestDistance(vector<vector<int>>& grid) {
        
        n = grid.size() , m = grid[0].size();
        int totalBuildings = 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1)
                    totalBuildings++;
            }
        }
        
        int minDist = INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 0)
                {
                    int currDist = checkDist(grid , i , j , totalBuildings);
                    minDist = min(minDist , currDist);
                }
            }
        }
        
        if(minDist == INT_MAX)
            return -1;
        
        return minDist;
        
    }
};