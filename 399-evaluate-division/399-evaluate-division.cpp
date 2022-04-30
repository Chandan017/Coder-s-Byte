class Solution {
public:
     unordered_map<string, vector<pair<string, double>>> graph;
    
    double get(vector<string> &query)
    {
        string from = query[0];
        string to = query[1];
        
        if(graph.find(from) == graph.end() || graph.find(to) == graph.end())
            return -1;
        
        queue<pair<string , double>> q;
        q.push({from , 1});
        unordered_set<string> vis;
        vis.insert(from);
        
        
        while(!q.empty())
        {
            string currNode = q.front().first;
            double currVal = q.front().second;
            q.pop();
            
            if(currNode == to)
                return currVal;
            
            for(auto it : graph[currNode])
            {
                string node = it.first;
                double weight = it.second;
                if(vis.insert(node).second)
                {
                    q.push({node , currVal*weight});
                   // vis.insert(node);
                }
            }
        }
            
        return -1;
    }
    
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
       
        for(int i=0;i<equations.size();i++)
        {
            auto from = equations[i][0];
            auto to = equations[i][1];
            double val = values[i];
            
            graph[from].push_back({to , val});
            graph[to].push_back({from , 1/val});
        }
        
        
        vector<double> res;
        
        for(auto query:queries)
        {
            double ans = get(query);
            res.push_back(ans);
        }
        
        return res;
        
    }
};