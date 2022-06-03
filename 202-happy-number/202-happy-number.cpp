class Solution {
public:
    
    int getNext(int n)
    {
        int totalSum = 0;
        
        while(n)
        {
            int digit = n%10;
            n /= 10;
            
            totalSum += (digit*digit);
        }
        
        return totalSum;
    }
    
    bool isHappy(int n) {
        
        
        while(n != 1 && n!=4)
        {
            n = getNext(n);
        }
        
        return n==1;
        
    }
};