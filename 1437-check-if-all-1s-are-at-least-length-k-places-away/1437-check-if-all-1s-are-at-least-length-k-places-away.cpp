class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        
        int prev = -1 , n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            if(nums[i] == 1)
            {
                if(prev == -1)
                    prev = i;
                else if(i-prev <= k )
                    return false;
                else
                    prev = i;
            }
        }
        
        return true;
        
    }
};