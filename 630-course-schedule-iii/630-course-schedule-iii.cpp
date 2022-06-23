class Solution {
public:
    static bool comp(vector<int> &a , vector<int> &b)
    {
        return a[1]<b[1];
            
    }
    
//     int solve(vector<vector<int>> &courses , int i ,int time ,vector<vector<int>> &dp)
//     {
//         if( i == courses.size())
//             return 0;
        
//         if(dp[i][time] != -1)
//             return dp[i][time];
        
//         int taken = 0;
//         if(time + courses[i][0] <= courses[i][1])
//             taken = 1 + solve(courses , i+1 , time + courses[i][0] , dp);
        
//         int notTaken = solve(courses, i+1 , time ,dp);
        
//         return dp[i][time] = max(taken , notTaken);
//     }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        
        sort(courses.begin() , courses.end() , comp);
        int n = courses.size();
        
        priority_queue<int> pq;
        int time = 0;
        for(auto it:courses)
        {
            time += it[0];
            pq.push(it[0]);
            
            if(time > it[1])
            {
                time -= pq.top();
                pq.pop();
            }
                
        }
        
        return pq.size();
        
        
        
        
    }
};