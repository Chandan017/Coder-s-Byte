class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int> indegree(n,0) , outdegree(n,0);
        
        for(auto it:trust)
        {
            indegree[it[1]-1]++;
            outdegree[it[0]-1]++;
        }
        
        
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==(n-1) && outdegree[i]==0)
                return (i+1);
        }
        
        return -1;
        
    }
};