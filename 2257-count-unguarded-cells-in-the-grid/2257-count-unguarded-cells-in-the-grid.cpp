class Solution {
public:
    
    bool isValid(int r , int c , vector<vector<int>> &grid , int m , int  n)
    {
        if(r>=m || c>=n || r<0 || c<0)
            return false;
        if(grid[r][c] == 1 || grid[r][c] == 2)
            return false;
        else
            return true;
    }
    
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        vector<vector<int>> grid(m,vector<int>(n,0));
        long long safe = m*n;
        
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        
        // marks walls as 1
        for(auto it:walls)
        {
            grid[it[0]][it[1]] = 1;
            
        }
        
        // mark guards as 2
        for(auto it:guards)
        {
            grid[it[0]][it[1]] = 2;
        }
        
        
        
        for(auto it:guards)
        {
            int r = it[0] , c = it[1];
            
            int notSafe = 0;
            
            for(int ind = 0 ; ind < 4 ; ind++)
            {
                int dupR = r+dx[ind] , dupC = c+dy[ind];
                
                while(isValid(dupR , dupC , grid , m , n))
                {
                    if(grid[dupR][dupC] != -1)
                        notSafe++;
                    
                    grid[dupR][dupC] = -1;
                    
                    dupR += dx[ind];
                    dupC += dy[ind];
                }
            }
            
            safe -= notSafe;
        }
        
        // walls and guards are also not safe place so subtract it
        
        safe -= walls.size();
        safe -= guards.size();
        
        return safe;
        
    }
};