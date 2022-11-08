class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        
        int prev = 0 , maxLen = 0 , zeroCnt = 0 , n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            if(nums[i] == 0)
                zeroCnt++;
            
            while(zeroCnt > k)
            {
                if(nums[prev] == 0)
                    zeroCnt--;
                prev++;
            }
            
            maxLen = max(maxLen , (i-prev+1));
        }
        
        return maxLen;
        
    }
};