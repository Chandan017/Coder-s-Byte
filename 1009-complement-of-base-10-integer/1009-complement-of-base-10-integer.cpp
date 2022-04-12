class Solution {
public:
    int bitwiseComplement(int n) {
        
        if(n==0)
            return 1;
        
        int temp = n;
        
        int mask = 0;
        
        while(temp)
        {
            temp = temp>>1;
            mask = (mask<<1) | 1; 
        }
        
        return (n^mask);
        
    }
};