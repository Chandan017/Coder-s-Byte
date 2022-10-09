class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        
        int prev = 0 , longestTask = -1 , empID = INT_MAX;
        
        for(auto &it:logs)
        {
            int currTime = it[1] - prev;
            
            if(currTime > longestTask)
            {
                longestTask = currTime;
                empID = it[0];
            }
            else if(currTime == longestTask)
            {
                empID = min(empID , it[0]);
            }
            prev = it[1];
        }
        
      
        return empID;
        
    }
};