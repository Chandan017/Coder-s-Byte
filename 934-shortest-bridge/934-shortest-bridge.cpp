class Solution {
public:
    
    int n,m;
    
    void floodFill(int r ,int c , vector<vector<int>> &grid)
    {
        queue<pair<int,int>> q;
        q.push({r,c});
        grid[r][c]=2;
        
        
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            
            for(int ind=0;ind<4;ind++)
            {
                int newX=x+dx[ind];
                int newY=y+dy[ind];
                
                if(newX>=0 && newY>=0 && newX< n && newY< m && grid[newX][newY]==1)
                {
                    q.push({newX,newY});
                    grid[newX][newY]=2;
                }
            }
        }
        
        return ;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        
        int hasDone=false;
        
        n=grid.size();
        m=grid[0].size();
        
        queue<pair<int,pair<int,int>>> q;
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    if(hasDone==false)
                    {
                        floodFill(i,j,grid); // chage color
                        hasDone=true;
                    }                    
                }
                if(grid[i][j]==2) // changed color of 1st island to recognize 
                    {
                        q.push({0,{i,j}});
                    }
            }
        }
        
        
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        
        
        cout<<endl<<endl;
        
        while(!q.empty())
        {
            int dist=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            
            q.pop();
            
            
            
            for(int ind=0;ind<4;ind++)
            {
                int newX=x+dx[ind];
                int newY=y+dy[ind];
                
                if(newX>=0 && newY>=0 && newX<n && newY<m && grid[newX][newY]<2)
                {
                    
                    if(grid[newX][newY]==1)
                        return dist;
                    q.push({dist+1 , {newX,newY}});
                    grid[newX][newY]=2; // mark visited
                }
            }
        }
        
        return -1;
    }
};