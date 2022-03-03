class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        
        int n=grid.size();
        
        if(grid[0][0]==1)
            return -1;
        queue<pair<int,pair<int,int>>> q;
        
        // {dist , {x,y}}
        q.push({1,{0,0}});
        grid[0][0]=1;
        
        int dx[]={-1,1,0,0,1,1,-1,-1};
        int dy[]={0,0,-1,1 , 1,-1,-1,1};
        while(!q.empty())
        {
            int dist=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            
            if(x==n-1 && y==n-1)
                return dist;
            
            for(int ind=0;ind<8;ind++)
            {
                int newX=x+dx[ind];
                int newY=y+dy[ind];
                
                if(newX>=0 && newX<n && newY>=0 && newY<n && grid[newX][newY]==0)
                {
                    grid[newX][newY]=1;
                    q.push({dist+1 , {newX , newY}});
                }
            }
        }
        
        return -1;
        
    }
};