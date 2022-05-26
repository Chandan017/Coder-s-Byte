class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int setBits = 0;
        
        while(n)
        {
            n = n&(n-1);
            setBits++;
        }
        
        
        return setBits;
        
    }
};