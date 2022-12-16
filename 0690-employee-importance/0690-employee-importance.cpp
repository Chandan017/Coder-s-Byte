/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        
        int n = employees.size();
        vector<vector<int>> adj(2001);
        map<int,int> imp;
        
        for(auto it:employees)
        {
            imp[it->id] = it->importance;
            
            for(auto j:it->subordinates)
            {
                adj[it->id].push_back(j);
            }
        }
        
        queue<int> q;
        q.push(id);
        int total = imp[id];
        
        
        while(q.size())
        {
            int curr = q.front();
            q.pop();
            
            for(auto j:adj[curr])
            {
                q.push(j);
                total += imp[j];
            }
        }
        
        return total;
    }
};