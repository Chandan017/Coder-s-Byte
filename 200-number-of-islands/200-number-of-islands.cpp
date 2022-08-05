class Solution {
public:
    int n , m;
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    
    void fill(vector<vector<char>> &grid , int r , int c)
    {
        if(r<0 || c<0 || r>=n || c>=m || grid[r][c] != '1')
            return ;
        
        grid[r][c] = '0';
        
        for(int ind = 0;ind<4;ind++)
        {
            int newR = r+dx[ind];
            int newC = c+dy[ind];
            
            fill(grid , newR , newC);
        }
        
        return ;
    }
    int numIslands(vector<vector<char>>& grid) {
        
        n = grid.size() , m = grid[0].size();
        int cntOfLands = 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == '1')
                {
                    fill(grid , i , j);
                    cntOfLands++;
                }
            }
        }
        
        return cntOfLands;
        
    }
};