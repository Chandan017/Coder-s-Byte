class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        int cnt = 0;
        if(n<=0)
            return false;
        while(n)
        {
            cnt++;
            n = n & (n-1);
        }
        
        return (cnt==1);
    }
};