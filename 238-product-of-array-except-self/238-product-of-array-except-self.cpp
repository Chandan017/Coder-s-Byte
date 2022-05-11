class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans;
        ans.push_back(1);
        for(int i=1;i<n;i++)
        {
            int prev = ans.back() * nums[i-1];
            ans.push_back(prev);
        }
        
        int runningProd = 1;
        for(int i=n-2;i>=0;i--)
        {
            int prev = runningProd * nums[i+1];
            ans[i] *= prev;
            
            runningProd = prev;
        }
       
        
        return ans;
        
    }
};