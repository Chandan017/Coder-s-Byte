class Solution {
public:
    int solve(vector<int> &nums , vector<int> &sum , int ind)
    {
        if(ind == nums.size())
        {
            return *max_element(sum.begin() , sum.end());
        }
        
        int ans = INT_MAX;
        
        for(int i=0;i<sum.size();i++)
        {
            sum[i] += nums[ind];
            int curr = solve(nums , sum , ind+1);
            ans = min(ans , curr);
            sum[i] -= nums[ind];
        }
        return ans;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        
        vector<int> sum(k);
        
        int ans = solve(cookies , sum , 0);
        return ans;
        
    }
};