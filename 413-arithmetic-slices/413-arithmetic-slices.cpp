class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int cnt=0 , ans=0;
        
        int n=nums.size();
        
        for(int i=2;i<n;i++)
        {
            if(nums[i-2]-nums[i-1]==nums[i-1]-nums[i])
                cnt++;
            else
                cnt=0;
            
            ans+=cnt;
        }
        
        return ans;
        
    }
};