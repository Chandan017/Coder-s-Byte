class Solution {
public:
    int longestMountain(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n<3)
            return 0;
        
        int maxiLen = 0;
        int i = 0;
        
        while(i<n)
        {
            int start = i;
            
            while(i+1 < n && nums[i+1] > nums[i])
                i++;
            
            if(i == start)
            {
                i++;
                continue;
            }
            
            int peakInd = i;
            
            while(i+1 < n && nums[i+1] < nums[i])
                i++;
            
            if(i == peakInd)
                continue;
            
            maxiLen = max(maxiLen , i-start+1);
        }
        
        return maxiLen;
        
    }
};