class Solution {
public:
    int n , m;
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    
    int getArea(vector<vector<int>> &grid , int r , int c)
    {
        if(r<0 || c<0 || r>=n || c>=m || grid[r][c] == 0)
            return 0;
        
        grid[r][c] = 0;
        int currArea = 1;
        
        for(int ind=0;ind<4;ind++)
        {
            int newR = r+dx[ind];
            int newC = c+dy[ind];
            
            currArea += getArea(grid , newR , newC);
        }
        
        return currArea;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        n = grid.size() , m = grid[0].size();
        
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