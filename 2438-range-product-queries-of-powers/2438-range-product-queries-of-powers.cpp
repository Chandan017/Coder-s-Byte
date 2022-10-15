class Solution {
public:
    int mod = 1e9 + 7;
    
    long getPower(long num)
    {
        long res = 1;
        
        while(num--)
        {
            res *= 2;
            res %= mod;
        }
            
        
        return res;
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        
        
        vector<int> prefixPower;
        prefixPower.push_back(0);
        
        int prefixSum = 0 , ind = 0;
        
        while(n)
        {
            int rem = n % 2;
            
            if(rem == 1)
            {
                prefixSum += ind;
                prefixPower.push_back(prefixSum);
            }
            
            ind++;
            n /= 2;
        }
        
        vector<int> res;
        for(auto it:queries)
        {
            int x = it[0] , y = it[1];
            
            long val = (prefixPower[y+1] - prefixPower[x]) % mod;
            val = getPower(val);            
            res.push_back(val);
        }
        
        
        return res;
        
        
    }
};