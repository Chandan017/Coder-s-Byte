class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        
        int prev = 0;
        vector<int> id(n,0);
        
        for(auto it:logs)
        {
            int currTime = it[1] - prev;
            
            id[it[0]] = max(currTime , id[it[0]]);
            prev = it[1];
        }
        
        int longestTask = -1 , empID = INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(id[i] > longestTask)
            {
                longestTask = id[i];
                empID = i;
            }   
        }
        
        return empID;
        
    }
};