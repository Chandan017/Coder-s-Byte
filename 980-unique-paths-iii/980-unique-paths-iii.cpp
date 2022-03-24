class Solution {
public:
    
    int n,m;
    int ways=0;
    
    void travel(vector<vector<int>> &grid , int sx , int sy , int coveredSquares , int totalSquares)
    {
        if(sx<0 || sy<0 || sx>=n || sy>=m || grid[sx][sy]==-1)
            return ;
        
        if(grid[sx][sy]==2)
        {
            if(coveredSquares==totalSquares)
            {
                ways++;
            }
            return ;
        }
        
        grid[sx][sy]=-1;
        
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        for(int ind=0;ind<4;ind++)
        {
            int newX=sx+dx[ind];
            int newY=sy+dy[ind];
            travel(grid , newX , newY , coveredSquares+1 , totalSquares);
            
        }
        
        grid[sx][sy]=0;
        return ;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        n=grid.size();
        m=grid[0].size();
        
        int sx,sy , emptySqaures=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    sx=i , sy=j;
                }
                else if(grid[i][j]==0 || grid[i][j]==2)
                    emptySqaures++;
            }
        }
        
        travel(grid , sx , sy , 0 , emptySqaures);
        
        
        return ways;
        
    }
};