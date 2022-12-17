class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        
        
        int cnt = 0;
        int n = nums.size();
        for(int i=0;i<n-1;i++)
        {
            int diff = nums[i+1]-nums[i] - 1;
                        
            if(diff >= k)
                return nums[i]+k;
            
            k -= diff;
        }
        
        return nums[n-1]+k;
        
    }
};