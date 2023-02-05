class Solution {
public:
    int get(int n)
    {
        int sum = 0;
        
        while(n)
        {
            int val = n%10;
            sum += (val*val);
            
            n /= 10;
        }
        
        return sum;
    }
    bool isHappy(int n) {
        
        int slow = n , fast = get(n);
        
        while(slow != fast && fast != 1)
        {
            slow = get(slow);
            fast = get(get(fast));
        }
        
        if(fast == 1)
            return true;
        
        return false;
        
    }
};