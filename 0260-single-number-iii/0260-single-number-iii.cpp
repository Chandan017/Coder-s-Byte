class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int XOR = 0;
        
        for(auto it:nums)
            XOR ^= it;
        
        int mask = 1;
        
        while(!(mask & XOR))
            mask = mask<<1;
        
        int firstBucket = 0 , secondBucket = 0;
        
        
        for(auto it:nums)
        {
            if(mask&it)
                firstBucket ^= it;
            else
                secondBucket ^= it;
        }
        
        return {firstBucket , secondBucket};
    }
};