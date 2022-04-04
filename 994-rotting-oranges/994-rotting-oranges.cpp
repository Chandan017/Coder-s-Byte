class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,pair<int,int>>> q;
        int totalOranges=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                    q.push({0 , {i,j}});
                if(grid[i][j]!=0)
                    totalOranges++;
            }
        }
        int dx[]={-1 , 1 , 0 ,0};
        int dy[]={0 , 0 , -1 , 1};
        int rottenOranges=0 , maxTime=0;
        while(!q.empty())
        {
            int currTime=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            
            maxTime=max(maxTime , currTime);
            
            for(int ind=0;ind<4;ind++)
            {
                int newX = x + dx[ind];
                int newY = y + dy[ind];
                
                if(newX>=0 && newY>=0 && newX<n && newY<m && grid[newX][newY]==1)
                {
                    grid[newX][newY] = 2;
                    q.push({currTime+1 , {newX , newY}});
                }
            }
            rottenOranges++;
        }
        
        if(rottenOranges == totalOranges)
            return maxTime;
        else
            return -1;
    }
};