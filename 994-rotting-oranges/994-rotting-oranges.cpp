class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,pair<int,int>>> q;
        int totalOranges=0;
        int n=grid.size();
        int m=grid[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({0 , {i,j}});
                }
                
                if(grid[i][j]!=0)
                    totalOranges++;
            }
        }
        
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        
        int rottenOranges=0;
        int maxTime=0;
        while(!q.empty())
        {
            
            int time=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            
            maxTime=max(maxTime,time);
            
            for(int ind=0;ind<4;ind++)
            {
                int newX=x+dx[ind];
                int newY=y+dy[ind];
                
                if(newX>=0 && newX<n && newY>=0 && newY<m && grid[newX][newY]==1)
                {
                    grid[newX][newY]=2;
                    q.push({time+1 , {newX,newY}});
                }
            }
            
            rottenOranges++;
            
        }
        
        if(rottenOranges==totalOranges)
            return maxTime;
        return -1;
        
    }
};