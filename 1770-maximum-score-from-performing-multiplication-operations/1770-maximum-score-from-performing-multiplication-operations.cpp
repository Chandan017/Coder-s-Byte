class Solution {
public:
    
    int n,m;
    
//     int get(vector<int> &nums , vector<int> &multi , int start , int ind , vector<vector<int>> &dp)
//     {
//         if(ind == m)
//             return 0;
        
//         if(dp[ind][start] != NULL)
//             return dp[ind][start];
        
      
        
//         int currFront = (nums[start]*multi[ind]) + get(nums , multi , start+1 , ind+1 , dp);
//         int currBack = (nums[(n-1) - (ind-start)]*multi[ind]) + get(nums , multi , start , ind+1 , dp);
        
        
//         return dp[ind][start] = max(currFront , currBack);
//     }
    
    
    int maximumScore(vector<int>& nums, vector<int>& multi) {
        
        n = nums.size() , m = multi.size();     
        vector<vector<int>> dp(m+1 , vector<int>(m+1 , 0));
        
        for(int ind=m-1;ind>=0;ind--)
        {
            for(int front=ind;front>=0;front--)
            {
                int currFront = multi[ind]*nums[front] + dp[ind+1][front+1];
                int currBack = multi[ind]*nums[n-1-(ind-front)] + dp[ind+1][front];
                dp[ind][front] = max(currBack , currFront);
            }
        }
        
        
        
        return dp[0][0];
        
    }
};