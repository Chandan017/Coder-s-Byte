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
        
        queue<Employee*> q;
        map<int , int> mpp;
        int n=employees.size();
        for(int i=0;i<n;i++)
        {
            if(employees[i]->id == id)
                q.push(employees[i]);
            
            mpp[employees[i]->id] = i;
        }

        int totalVal =0;
        while(!q.empty())
        {
            auto emp = q.front();
            totalVal += emp->importance;
            q.pop();
            
            for(auto it:emp->subordinates)
            {
                int currEmp = mpp[it];
                q.push(employees[currEmp]);
                
            }
        }
            
        return totalVal;
        
    }
};