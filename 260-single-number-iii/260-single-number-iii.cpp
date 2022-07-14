class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int XOR = 0 ;
        
        for(auto it:nums)
            XOR ^= it;
    
        
        int mask = 1;
        
        while((mask & XOR) == 0)
            mask = mask<<1;
        
        int bucket1 = 0 , bucket2=0;
       
        for(auto it:nums)
        {
            
            if((mask&it) == 0)
                bucket1 ^= it;
            else
                bucket2 ^= it;
        }
        
        return {bucket1 , bucket2};
        
        
        
    }
};