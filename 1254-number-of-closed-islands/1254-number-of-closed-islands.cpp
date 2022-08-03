class Solution {
public:
    
    int n , m;
    
    void fill(vector<vector<int>> &grid , int r , int c)
    {
        if(r<0 || c<0 || r>=n || c>=m || grid[r][c] != 0)
            return ;
        
        grid[r][c] = 1;
        
        fill(grid , r+1 , c );
        fill(grid , r-1 , c);
        fill(grid , r , c+1);
        fill(grid , r , c-1);
        
        return ;
    }
    int closedIsland(vector<vector<int>>& grid) {
        
        n = grid.size() , m= grid[0].size();
        
        for(int i=0;i<n;i++)
        {
            if(grid[i][0] == 0)
                fill(grid , i , 0);
            if(grid[i][m-1] == 0)
                fill(grid , i , m-1);
        }
        
        
        for(int j=0;j<m;j++)
        {
            if(grid[0][j] == 0)
                fill(grid , 0 , j);
            
            if(grid[n-1][j] == 0)
                fill(grid , n-1 , j);
        }
        
        int cnt = 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 0)
                {
                    fill(grid , i , j);
                    cnt++;
                }
            }
        }
        
        return cnt;
        
        
    }
};