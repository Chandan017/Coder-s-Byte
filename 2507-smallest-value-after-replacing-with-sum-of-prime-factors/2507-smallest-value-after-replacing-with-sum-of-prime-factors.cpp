class Solution {
public:
    int smallestValue(int n) {
        
        while(n)
        {
            int prev = n , sum = 0;
            
            for(int i=2;i<=n;)
            {
                if(n%i==0)
                {
                    sum += i;
                    n /= i;
                }
                else
                    i++;
            }
            
            if(prev == sum)
                return sum;
            
            n = sum;
        }
        return 0;
    }
};