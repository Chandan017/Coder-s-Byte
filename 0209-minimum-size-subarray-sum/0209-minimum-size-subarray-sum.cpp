class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int prev = 0 , n = nums.size();
        int minLen = INT_MAX , sum = 0;
        
        for(int i=0;i<n;i++)
        {
            sum += nums[i];
            
            if(sum >= target)
            {
                while(prev < n)
                {
                    if(sum - nums[prev] >= target)
                    {
                        sum -= nums[prev];
                        prev++;
                    }
                    else
                        break;
                }
                    
                int currLen = i-prev+1;
                
                minLen = min(minLen , currLen);
                sum -= nums[prev];
                prev++;
            }
        }
        
        // while(prev < n && sum >= target)
        // {
        //     int currLen = n-prev;
        //     minLen = min(minLen , currLen);
        //     sum -= nums[prev];
        //     prev++;
        // }
        
        // cout<<endl;
        if(minLen == INT_MAX)
            return 0;
        
        
        
        return minLen;
        
    }
};