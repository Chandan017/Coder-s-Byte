class Solution {
public:
    int countPrimes(int n) {
        
        if(n<=2)
            return 0;
        vector<bool> isPrime(n,true);
        
        isPrime[0]=false;
        isPrime[1]=false;
       
        
        for(int i=2;i*i<n;i++)
        {
            if(isPrime[i])
            {
                int j=i*2;
                while(j<n)
                {
                    isPrime[j]=false;
                    j=j+i;
                }
            }
        }
        
        
        int cnt=0;
        for(auto it:isPrime)
        {
            if(it)
                cnt++;
        }
        
        return cnt;
        
        
    }
};