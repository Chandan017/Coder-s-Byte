class Solution {
public:
    
    vector<int> solve(int node , int parent , vector<vector<int>> &adj , string &labels , vector<int> &res)
    {
        vector<int> nodeCnt(26 , 0);
        nodeCnt[labels[node]-'a'] = 1;
        
        for(auto it:adj[node])
        {
            if(it != parent)
            {
                vector<int> childCnt = solve(it , node , adj , labels , res);
                
                for(int i=0;i<26;i++)
                {
                    nodeCnt[i] += childCnt[i];
                }
            }
        }
        
        
        res[node] = nodeCnt[labels[node]-'a'];
        return nodeCnt;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        
        
        vector<vector<int>> adj(n);
        
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> res(n,0);
        
        solve(0 , -1 , adj , labels , res);
        
        return res;
    }
};