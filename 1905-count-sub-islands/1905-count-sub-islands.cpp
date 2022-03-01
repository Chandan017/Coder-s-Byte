class Solution {
    
private:
    int n,m;
    bool floodFill(int r,int c,vector<vector<int>> &grid1 , vector<vector<int>> &grid2)
    {
        queue<pair<int,int>> q;
        q.push({r,c});
        grid2[r][c]=0;
        bool hasIsland=true;
        
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            
            if(grid1[x][y]!=1)
            {
                hasIsland=false;
            }
            
            for(int ind=0;ind<4;ind++)
            {
                int newX=x+dx[ind];
                int newY=y+dy[ind];
                
                if(newX>=0 && newY>=0 && newX<n && newY<m && grid2[newX][newY]==1)
                {
                    grid2[newX][newY]=0;
                    q.push({newX,newY});
                }
            }
            
            
            
        }
        
        return hasIsland;
       
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        
        n=grid1.size();
        m=grid1[0].size();
        
        
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid2[i][j]==1)
                {
                    bool curr=floodFill(i,j,grid1,grid2);
                    cnt+=curr;
                }
            }
        }
        
        return cnt;
    }
};