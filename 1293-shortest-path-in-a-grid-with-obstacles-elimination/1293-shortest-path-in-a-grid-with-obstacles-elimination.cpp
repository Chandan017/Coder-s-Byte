class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,-1));
        
        queue<vector<int>> q; // x,y,currlength , k (how many obstacles can be remove)
        q.push({0,0,0,k});
        
        
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        while(!q.empty())
        {
            auto temp=q.front();
            int x=temp[0] , y=temp[1];
            q.pop();
            
            if(x==n-1 && y==m-1)
                return temp[2];
            
            if(grid[x][y]==1)
            {
                if(temp[3] >0)
                    temp[3]--;
                else 
                    continue;
            }
            
            if(vis[x][y]!=-1 && vis[x][y] >= temp[3])
                continue;
            vis[x][y]=temp[3];
            
            for(int ind=0;ind<4;ind++)
            {
                int newX=x+dx[ind];
                int newY=y+dy[ind];
                
                if(newX>=0 && newY>=0 && newX<n && newY<m )
                    q.push({newX,newY , temp[2]+1 , temp[3]});
            }
                
            
        }
        
        return -1;
        
    }
};