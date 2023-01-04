class Solution {
public:
    
    bool check(vector<vector<int>> &grid , int r , int c)
    {
        int n = grid.size();
        
        for(int i=0;i<n;i++)
        {
            if(grid[r][i] != grid[i][c])
                return false;
        }
        
        return true;
    }
    int equalPairs(vector<vector<int>>& grid) {
        
        int n = grid.size() , cnt = 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(check(grid , i , j))
                    cnt++;
            }
        }
        
        return cnt;
        
    }
};