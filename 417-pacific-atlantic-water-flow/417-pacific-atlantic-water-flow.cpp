class Solution {
public:
    
    void bfs(vector<vector<int>>& heights , vector<vector<bool>> & vis , queue<pair<int,int>> &q)
    {
        int n=heights.size();
        int m=heights[0].size();
        
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            
            vis[x][y]=1;
            
            for(int ind=0;ind<4;ind++)
            {
                int newX=x+dx[ind];
                int newY=y+dy[ind];
                
                if(newX>=0 && newY>=0 && newX<n && newY<m && heights[newX][newY] >= heights[x][y] && vis[newX][newY]==0)
                {
                    q.push({newX,newY});
                }
                    
            }
        }
        
        return ;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<bool>> pacific(n,vector<bool>(m,0));
         vector<vector<bool>> atlantic(n,vector<bool>(m,0));
        
        vector<vector<int>> ans;
        
        queue<pair<int,int>> pac ,atl;
        
        
        
        for(int i=0;i<n;i++)
        {
            pac.push({i,0});
            atl.push({i,m-1});
           
        }
        for(int j=0;j<m;j++)
        {
            pac.push({0,j});
            atl.push({n-1,j});
            
        }
        

        
        bfs(heights , pacific , pac);
        
        bfs(heights , atlantic, atl);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(atlantic[i][j]==1 && pacific[i][j]==1)
                    ans.push_back({i,j});
            }
        }
        
        return ans;
        
        
        
        
        
        
    }
};