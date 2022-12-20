class Solution {
public:
    vector<int> parent;
    int getParent(int x)
    {
        if(parent[x] == x)
            return x;
        return getParent(parent[x]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        parent.resize(n+1 , 0);
        
        for(int i=0;i<=n;i++)
            parent[i] = i;
        
        vector<int> res;
        for(auto it:edges)
        {
            int firstParent = getParent(it[0]);
            int secondParent = getParent(it[1]);
            
            if(firstParent != secondParent)
            {
                parent[firstParent] = secondParent;
            }
            else
            {
                res.push_back(it[0]);
                res.push_back(it[1]);
                break;
            }
        }
        
        return res;
        
    }
};