class Solution {
public:
    unordered_map<string,vector<string>> adj;
    unordered_set<string> vis;


    void takeAll(string node , vector<string> &curr)
    {
        vis.insert(node);
        curr.push_back(node);
        
        for(auto it:adj[node])
        {
            if(vis.find(it) == vis.end())
            {
                takeAll(it , curr);
            }
        }
        
        return ;
        
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        
        for(auto &it:accounts)
        {
            string firstMail = it[1];
            
            for(int i=2;i<it.size();i++)
            {
                adj[firstMail].push_back(it[i]);
                adj[it[i]].push_back(firstMail);
            }
        }
        
        
        vector<vector<string>> res;
        
        for(auto &it:accounts)
        {
            string name = it[0] , firstMail = it[1];
            
            if(vis.find(firstMail) == vis.end())
            {
                vector<string> curr;
                takeAll(firstMail , curr);
                
                sort(curr.begin() , curr.end());
                curr.insert(curr.begin() , name);
                
                res.push_back(curr);
            }
            
        }
        
        
        return res;
        
        
        
    }
};