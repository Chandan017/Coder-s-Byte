class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> left;
        left.push_back(1);
        for(int i=1;i<n;i++)
        {
            int prev = left.back() * nums[i-1];
            left.push_back(prev);
        }
        
        vector<int> right;
        right.push_back(1);
        
        for(int i=n-2;i>=0;i--)
        {
            int prev = right.back() * nums[i+1];
            right.push_back(prev);
        }
        
        vector<int> ans;
        reverse(right.begin() , right.end());
        
        for(int i=0;i<n;i++)
        {
            int val = left[i] * right[i];
            
            ans.push_back(val);
        }
        
        return ans;
        
    }
};