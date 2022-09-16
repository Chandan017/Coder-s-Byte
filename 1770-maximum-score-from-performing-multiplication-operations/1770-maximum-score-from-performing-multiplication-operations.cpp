class Solution {
public:
   
    
    int maximumScore(vector<int>& nums, vector<int>& multi) {
        
        int n = nums.size() , m = multi.size();     
        vector<vector<int>> dp(m+1 , vector<int>(m+1 , 0));
        
        for(int ind=m-1;ind>=0;ind--)
        {
            for(int front=ind;front>=0;front--)
            {
                int currFront = multi[ind]*nums[front] + dp[ind+1][front+1];
                int currBack = multi[ind]*nums[(n-1)-(ind-front)] + dp[ind+1][front];
                dp[ind][front] = max(currBack , currFront);
            }
        }
        
        
        
        return dp[0][0];
        
    }
};