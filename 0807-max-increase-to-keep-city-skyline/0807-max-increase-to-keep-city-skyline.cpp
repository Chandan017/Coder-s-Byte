class Solution {
public:
    int getRowMax(vector<vector<int>> &grid , int r)
    {
        int maxi = 0;
        for(int j=0;j<grid.size();j++)
        {
            maxi = max(maxi , grid[r][j]);
        }
        
        return maxi;
    }
    
    int getColMax(vector<vector<int>> &grid, int c)
    {
        int maxi = 0;
        for(int i=0;i<grid.size();i++)
        {
            maxi = max(maxi , grid[i][c]);
        }
        
        return maxi;
    }
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        
        int total = 0 , n = grid.size();
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int rowMax = getRowMax(grid , i);
                int colMax = getColMax(grid , j);
                int val = min(rowMax , colMax);
                
                total += abs(grid[i][j] - val);
            }
        }
        
        return total;
        
    }
};