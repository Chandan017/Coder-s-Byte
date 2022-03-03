class Solution {
    
public:
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> dist(n,vector<int> (m,INT_MAX));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        
        
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
                
                if(newX>=0 && newY>=0 && newX<n && newY<m && dist[newX][newY] > dist[x][y]+1 )
                {
                    dist[newX][newY]=dist[x][y]+1;
                    q.push({newX , newY});
                }
            }
        }
        
        
        
        return dist;
        
    }
};