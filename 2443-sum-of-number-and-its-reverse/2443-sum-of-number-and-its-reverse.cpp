class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        
        
        int currNum = 0;
        
        while(currNum <= num)
        {
            int temp = currNum;
            int rev = 0;
            
            while(temp)
            {
                rev = (rev*10) + (temp%10);
                temp /= 10;
            }
            
            if(currNum + rev == num)
                return true;
            currNum++;
        }
        
        return false;
        
    }
};