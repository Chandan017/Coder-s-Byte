class Solution {
public:

    long long cnt ;
   
    
    bool valid(int dupR , int dupC ,vector<vector<int>> &grid , int m , int n , int r , int c)
    {
        if(dupR>=m || dupC>=n || dupR<0 || dupC<0)
            return false;
        if(grid[dupR][dupC]==1 || grid[dupR][dupC] == 2)
            return false;
        return true;
        
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        vector<vector<int>> grid(m , vector<int>(n , 0));
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
    
        cnt = m*n;
        for(int i=0;i<walls.size();i++)
        {
            grid[walls[i][0]][walls[i][1]] = 1;
        }
        
        for(int i=0;i<guards.size();i++)
        {
            grid[guards[i][0]][guards[i][1]] = 2;
        }
        
        
        for(auto it:guards)
        {
            int r = it[0] , c = it[1];
            int occupied=0;
            for(int ind=0;ind<4;ind++)
            {
                int dupR=r+dx[ind] , dupC=c+dy[ind];
                
                while(valid(dupR,dupC , grid , m , n , r , c)==true)
                 {
                    if(grid[dupR][dupC] != -1)
                        occupied++;
                    grid[dupR][dupC]=-1;
                    dupR += dx[ind];
                    dupC += dy[ind];
                }
            }
           cnt-= occupied;
        }
    
        cnt -= guards.size();
        return cnt-walls.size();
    }
};