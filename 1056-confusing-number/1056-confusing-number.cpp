class Solution {
public:
    bool confusingNumber(int n) {
        
        int original = n;
        long rev = 0;
        while(n)
        {
            int val = n%10;
            
            if(val == 0 || val == 1 || val == 6 || val == 9 || val == 8)
            {
                rev = rev*10;
                if(val == 6)
                    rev += 9;
                else if(val == 9)
                    rev += 6;
                else 
                    rev += val;
                
                n /= 10;
            }
            else
                return false;
        }
        
        
        return !(rev == original);
        
    }
};