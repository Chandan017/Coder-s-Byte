class Solution {
public:

    int countHousePlacements(int n) {

        int mod = 1e9+7;
        long first = 1 , second = 1 , total = 2;
        
        for(int i=2;i<=n;i++)
        {
            second = first;
            first = total;
            total = (first + second)%mod;
        }
        
        return (total*total)%mod;
        
     
        
    }
};