class Solution {
public:
    int climbStairs(int n) {
        
        if(n==1)
            return 1;
        
        int a = 1 , b=1;
        
        for(int i=2;i<=n;i++)
        {
            int c = a+b;
            a=b;
            b=c;
        }
        
        return b;
        
    }
};