class Solution {
public:
    
    bool check(int r1 , int c1 , int r2 , int c2 , vector<vector<bool>> &vis)
    {
        for(int i=r1;i<=r2;i++)
        {
            for(int j=c1;j<=c2;j++)
            {
                if(!vis[i][j])
                    return false;
            }
        }
        
        return true;
    }
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        
        vector<vector<bool>> vis(n,vector<bool> (n,false));
        
        for(int i=0;i<dig.size();i++)
        {
            int x=dig[i][0] , y=dig[i][1];
            
            vis[x][y]=true;
        }
        
        int cnt=0;
        for(int i=0;i<artifacts.size();i++)
        {
            int r1=artifacts[i][0]  , c1=artifacts[i][1]  , r2=artifacts[i][2] , c2=artifacts[i][3];
            
            if(vis[r1][c1] && vis[r2][c2])
            {
                if(check(r1,c1,r2,c2 , vis)==true)
                {
                    cnt++;
                   
                }
            }
        }
        
        return cnt;
        
    }
};