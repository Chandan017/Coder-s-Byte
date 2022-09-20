class Solution {
public:
    int n,m , maxLen = 0;
    vector<vector<int>> dp;
    int solve(vector<int> &nums1 , vector<int> &nums2 , int ind1 , int ind2)
    {
        if(ind1>=n || ind2>=m)
           return 0;
        
        if(dp[ind1][ind2] != -1)
            return dp[ind1][ind2];
        
        
        if(nums1[ind1] == nums2[ind2])
            dp[ind1][ind2] = 1 + solve(nums1 , nums2 , ind1+1 ,ind2+1);
        else
            dp[ind1][ind2] = 0;
        solve(nums1 , nums2 ,ind1+1 , ind2);
        solve(nums1 , nums2 , ind1 , ind2+1);
        
        maxLen = max(maxLen , dp[ind1][ind2]);
        return dp[ind1][ind2];
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        n = nums1.size() , m = nums2.size();
        dp.resize(n , vector<int> (m , -1));
        int res = solve(nums1 , nums2 , 0 , 0);
       
        return maxLen;
        
    }
};