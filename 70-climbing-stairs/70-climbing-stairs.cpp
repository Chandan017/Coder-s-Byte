class Solution {
public:
    int climbStairs(int n) {
        
        if(n==1)
            return 1;
        
        int first = 1 , second=1;
        int res;
        for(int i=2;i<=n;i++)
        {
            res = first + second;
            first = second;
            second = res;
        }
        
        return res;
        
    }
};