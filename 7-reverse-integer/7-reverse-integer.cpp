class Solution {
public:
    int reverse(int x) {
        
        bool isPositive;
        
        if(x<0)
            isPositive = false;
        else
            isPositive = true;
        
        x = abs(x);
        
        int rev = 0;
        
        while(x)
        {
            if(rev > INT_MAX/10 || rev < INT_MIN/10)
                return 0;
            
            rev = rev*10 + (x%10);
            
            x/=10;
        }
        
        if(isPositive==false)
            rev = 0 - rev;
        
        return rev;
        
    }
};