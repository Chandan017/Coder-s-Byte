class Solution {
    
private:
    int n,m;
    
    bool isValid(int x,int y)
    {
        return (x>=0 || y>=0 || x<n || y<m);
    }
    
    
    void floodFill(int x,int y,vector<vector<int>> &grid)
    {
        if(x<0 || y<0 || x>=n || y>=m || grid[x][y]!=1)
            return ;
        
        grid[x][y]=0;
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        
        for(int ind=0;ind<4;ind++)
        {
            int newX=x+dx[ind];
            int newY=y+dy[ind];
            
            floodFill(newX,newY,grid);
        }
        
        return ;
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        n=grid.size();
        m=grid[0].size();
        
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==1)
                floodFill(i,0,grid);
            
            if(grid[i][m-1]==1)
                floodFill(i,m-1,grid);
        }
        
        
        for(int j=0;j<m;j++)
        {
            if(grid[0][j]==1)
                floodFill(0,j,grid);
            if(grid[n-1][j]==1)
                floodFill(n-1,j,grid);
        }
        
        
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                    cnt++;
            }
        }
        
        
        return cnt;
        
    }
};