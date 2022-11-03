class Solution {
public:
    int averageValue(vector<int>& nums) {
        
        int sum = 0 , n = 0;
        
        for(auto it:nums)
        {
            if(it%2==0 && it%3==0)
            {
                sum += it;
                n++;
            }
        }
        
        
        int res = sum;
        
        if(sum)
            res /= n;
        
        return res;
    }
};