class Solution {
public:
    int trailingZeroes(int n) {
        
        int cnt = 0;
        
        for(int i=5;i<=n;i+=5)
        {
            int curr = i;
            while(curr%5 == 0)
            {
                cnt++;
                curr /= 5;
            }
        }
        
        return cnt;
    }
};