class Solution {
public:
    int totalBoxes = 0 , n , m , ways = 0;
    
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    
    void solve(vector<vector<int>> &grid , int r , int c , int coveredBoxes)
    {
        if(r<0 || c<0 || r>=n || c>=m || grid[r][c] == -1)
            return ;
        
        if(grid[r][c] == 2)
        {
            if(coveredBoxes == totalBoxes)
                ways++;
            return ;
        }
        
        grid[r][c] = -1;
        
        for(int ind=0;ind<4;ind++)
        {
            int newR = r+dx[ind];
            int newC = c+dy[ind];
            
            solve(grid , newR , newC , coveredBoxes+1);
        }
        
        grid[r][c] = 0;
        
        return ;
        
        
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        n = grid.size() , m = grid[0].size();
        
        int sx , sj;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] != -1)
                    totalBoxes++;
                
                if(grid[i][j] == 1)
                {
                    sx = i;
                    sj = j;
                }
            }
        }
                
        solve(grid , sx , sj , 1);
        
        return ways;
        
    }
};