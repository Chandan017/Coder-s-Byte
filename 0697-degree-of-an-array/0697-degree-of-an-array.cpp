class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        
        int n = nums.size();
        map<int,int> freq , lastOcc , firstOcc;
        int maxFreq = 0 , minLen = n;
        for(int i=0;i<n;i++)
        {
            freq[nums[i]]++;
            
            if(firstOcc.find(nums[i]) == firstOcc.end())
                firstOcc[nums[i]] = i;
            
            lastOcc[nums[i]] = i;
            
            if(freq[nums[i]] > maxFreq)
            {
                maxFreq = freq[nums[i]];
                int currLen = lastOcc[nums[i]] - firstOcc[nums[i]] + 1;
                minLen = currLen;
                
            }
            else if(freq[nums[i]] == maxFreq)
            {
                int currLen = lastOcc[nums[i]] - firstOcc[nums[i]] + 1;
                
                minLen = min(minLen , currLen);
            }
            
        }
        return minLen;
        
        
        
        
        
    }
};