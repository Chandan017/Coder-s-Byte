class Solution {
public:
    int n,m;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    
    int getArea(vector<vector<int>> &grid , int r , int c){
        
        queue<pair<int,int>> q;
        q.push({r,c});
        grid[r][c] = 0;
        
        int area = 0;
        
        while(q.size())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int ind=0;ind<4;ind++)
            {
                int newR = r+dx[ind];
                int newC = c+dy[ind];
                
                if(newR>=0 && newC>=0 && newR<n && newC<m && grid[newR][newC]==1)
                {
                    q.push({newR , newC});
                    grid[newR][newC] = 0;
                }
            }
            
            area++;
        }
        
        
        return area;
        
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        n = grid.size();
        m = grid[0].size();
        int maxArea = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1)
                {
                    int currArea = getArea(grid , i , j);
                    
                    maxArea = max(maxArea , currArea);
                }
            }
        }
        
        
        return maxArea;
        
    }
};