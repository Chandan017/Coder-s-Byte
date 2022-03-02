class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        queue<pair<int,int>> q;
        int n=grid.size() , m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                    q.push({i,j});
            }
        }
        
        if(q.size()==n*m)
            return -1;
        
        
        int dist=0;
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        while(!q.empty())
        {
            int size=q.size();
            dist++;
            
            while(size--)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                
                for(int ind=0;ind<4;ind++)
                {
                    int newX=x+dx[ind];
                    int newY=y+dy[ind];
                    
                    if(newX>=0 && newY>=0 && newX<n && newY<m && grid[newX][newY]==0)
                    {
                        q.push({newX,newY});
                        grid[newX][newY]=1;
                    }
                }
            }
        }
        
        
        return dist-1;
        
        
        
        
        
    }
};