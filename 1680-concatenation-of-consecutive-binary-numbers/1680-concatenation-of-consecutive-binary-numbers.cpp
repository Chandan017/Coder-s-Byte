class Solution {
public:
    
   
    int concatenatedBinary(int n) {
        
        string res = "";
        
        for(int i=n;i>=1;i--)
        {
            int num = i;
            
            while(num)
            {
                res += ((num%2)+'0');
                num /=2;
            }
        }
        
        int mod = 1e9 + 7;
        long long ans=0;
        int len = res.length();
        long long pow2 = 1;
        for(int i=0;i<len;i++)
        {
            long long currVal = (res[i]-'0') * pow2;
            pow2 *= 2;
            pow2 = pow2%mod;
    
            ans += currVal;
        }
        
        
        return ans%mod;
        
    }
};