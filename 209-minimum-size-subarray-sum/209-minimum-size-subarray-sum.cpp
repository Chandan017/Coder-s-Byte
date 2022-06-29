class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size();
        int minLen = n+1 , currSum = 0;
        
        int j=0;
        
        for(int i=0;i<n;i++)
        {
            if(currSum < target)
            {
                currSum += nums[i];
            }
            
            if(currSum >=target)
            {
                while(currSum >= target && j<n)
                {
                    int currLen = i-j+1;
                    minLen = min(minLen , currLen);
                    currSum -= nums[j];
                    j++;
            
                }
                
            }
            
            
        }
        cout<<minLen<<"->"<<j<<endl;
        
        while(currSum >= target && j<n)
        {
            int currLen = n-j;
            minLen = min(minLen , currLen);
            currSum -= nums[j];
            j++;
            
        }
        
        
        if(minLen == n+1)
            return 0;
        
        return minLen;
        
    }
};