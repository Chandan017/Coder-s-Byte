class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        
        sort(nums.begin() , nums.end());
        long long sum = 0 , start = 0;
        for(auto it:nums)
        {
            long long diff = it - start - 1;
            if(diff <= 0)
            {
                start = it;
                continue;
            }
            
            if(diff >= k)
            {
                long long range = start+k;
                k = 0;
                sum += (range*(range+1))/2 - (start*(start+1))/2;
                break;
            }
            
            k -= diff;
            long long range = it-1;
            sum += (range*(range+1))/2 - (start*(start+1))/2;
            start = it;
            
        }
        
        if(k)
        {
            long long range = start+ k;
            sum += (range*(range+1))/2 - (start*(start+1))/2;
        }
        
        
        
        return sum;
        
    }
};