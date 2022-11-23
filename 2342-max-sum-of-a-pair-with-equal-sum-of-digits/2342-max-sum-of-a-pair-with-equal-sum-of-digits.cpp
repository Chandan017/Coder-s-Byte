class Solution {
public:
    
    int getDigitSum(int n)
    {
        int sum = 0;
        
        while(n)
        {
            sum += (n%10);
            n /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        
        
        unordered_map<int , vector<int>> mpp;
        
        for(auto it:nums)
        {
            int digitSum = getDigitSum(it);
            
            mpp[digitSum].push_back(it);
        }
        
        int maxSum = -1;
        
        for(auto it:mpp)
        {
            if(it.second.size() > 1)
            {
                int firstMax = 0 , secondMax = 0;
                
                for(auto j:it.second)
                {
                    if(j > firstMax)
                    {
                        secondMax = firstMax;
                        firstMax = j;
                    }
                    else if(j <= firstMax && j > secondMax)
                    {
                        secondMax = j;
                    }
                }
                
                if(firstMax != 0 && secondMax != 0)
                {
                    int currSum = firstMax + secondMax;
                    
                    maxSum = max(maxSum , currSum);
                }
            }
        }
        
        return maxSum;
    }
};