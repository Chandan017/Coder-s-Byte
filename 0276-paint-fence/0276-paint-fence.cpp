class Solution {
public:
    int solve(int n , int k)
    {
        if(n==1)
            return k;
        if(n == 2)
            return k*k;
        
       int ans = (k-1)*solve(n-1 , k) + (k-1)*solve(n-2 , k);
    
        return ans;
        
    }
    int numWays(int n, int k) {
        
        int res = solve(n , k );
        
        return res;
    }
};