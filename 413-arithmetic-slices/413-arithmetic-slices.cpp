class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int cnt=0 , ans=0;
        
        for(int i=2;i<nums.size() ; i++)
        {
            if(nums[i-1]-nums[i-2] == nums[i]-nums[i-1])
                cnt++;
            else
                cnt=0;
            
            ans+=cnt;
        }
        
        return ans;
    }
};