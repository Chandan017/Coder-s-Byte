class Solution {
public:
    int dp[1001];
    int get(vector<int> &cost , int ind , int n)
    {
        if(ind >=n)
            return 0;
        
        if(dp[ind])
            return dp[ind];
        
        int takeIt = cost[ind] + min( get(cost , ind+1 , n ) , get(cost , ind+2 , n));
        
        return dp[ind] = takeIt;
    }
    int minCostClimbingStairs(vector<int>& cost) {
     
        int n=cost.size();
        
        int zeroIndex = get(cost , 0 , n);
        int oneIndex = get(cost , 1 , n);
        
        return min(zeroIndex , oneIndex);
    }
};