class Solution {
public:
    int solve(vector<int> &nums1 , vector<int> &nums2)
    {
        int n = nums1.size() , m = nums2.size() , maxLen = 0;
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(nums1[i-1] == nums2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = 0;
                
                maxLen = max(maxLen , dp[i][j]);
            }
        }
        
        return maxLen;
        
        
       
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
              
        return solve(nums1 , nums2);
        
    }
};