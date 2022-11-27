class Solution {
public:
    int pivotInteger(int n) {
        
        int sum = (n*(n+1)) / 2;
        
        int x = 1;
        
        while(x<=n)
        {
            int curr =(x*(x+1))/2;

            if(curr == (sum - curr + x))
                return x;
            x++;
        }
        
        return -1;
    }
};