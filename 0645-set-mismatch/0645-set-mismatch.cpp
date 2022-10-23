class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        int n = nums.size() , currXOR = 0;
        
        for(int i=0;i<n;i++)
        {
            currXOR ^= nums[i];
            currXOR ^= (i+1);
        }
        
        int mask = 1;
        
        while((mask & currXOR) == 0)
            mask = mask<<1;
        
        int firstNum = 0 , secondNum = 0;
        
        for(auto it:nums)
        {
            if((mask & it) == 0)
                firstNum ^= it;
            else
                secondNum ^= it;
        }
        
        for(int i=1;i<=n;i++)
        {
            if((mask & i) == 0)
                firstNum ^= i;
            else
                secondNum ^= i;
        }
        
        for(auto it:nums)
        {
            if(it == firstNum)
            {
                return {firstNum , secondNum};
            }
        }
        
        return {secondNum , firstNum};
        
       
        
    }
};