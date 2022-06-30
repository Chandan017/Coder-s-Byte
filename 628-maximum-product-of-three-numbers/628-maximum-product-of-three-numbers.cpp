class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        int firstMax = INT_MIN , secondMax = INT_MIN , thirdMax = INT_MIN;
        int firstMin = INT_MAX , secondMin = INT_MAX;
        
        for(auto it:nums)
        {
            if(it>=firstMax)
            {
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = it;
            }
            else if(it>=secondMax && it<firstMax)
            {
                thirdMax = secondMax;
                secondMax = it;
            }
            else if(it>thirdMax && it<secondMax)
            {
                thirdMax = it;
            }
            
            if(it<=firstMin)
            {
                secondMin = firstMin;
                firstMin = it;
            }
            else if(it<secondMin && it>firstMin)
                secondMin = it;
        }
        
        int ans1 = firstMax*secondMax*thirdMax;
        int ans2 = firstMin * secondMin * firstMax;
        
        return max(ans1 , ans2);
        
    }
};