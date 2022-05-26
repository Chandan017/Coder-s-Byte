class Solution {
public:
    int tribonacci(int n) {
        
        int first = 0 , second = 1, third = 1;
        
        if(n==0)
            return 0;
        if(n==1 || n==2)
            return 1;
        
        int nthNumber;
        n=n-2;
        while(n--)
        {
            nthNumber = first + second + third;
            
            first = second;
            second = third;
            third = nthNumber;
            
        }
        
        
        return nthNumber;
    }
};