class Solution {
public:
    int fib(int n) {
        
        if(n==0 || n==1)
            return n;
        
        int first = 0 , second = 1;
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