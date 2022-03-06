class Solution {
public:
    
    int n;
    void dfs(int node , vector<bool> &vis , vector<vector<int>> &isConnected)
    {
        vis[node]=1;
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i] && isConnected[node][i]==1)
                dfs(i,vis,isConnected);
        }
        
        return ;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        n=isConnected.size();
        
        vector<bool> vis(n+1 , 0);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i ,vis , isConnected);
                cnt++;
            }
        }
        
        return cnt;
        
    }
};