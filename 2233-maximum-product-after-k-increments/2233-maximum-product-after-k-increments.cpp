class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        
        long long product = 1;
        
        priority_queue<int, vector<int> ,greater<int>> pq;
        
        for(auto it:nums)
            pq.push(it);
        
        while(k)
        {
            int num = pq.top();
            pq.pop();
            if(k>0)
            {
                num++;
                k--;
            }
            
            pq.push(num);
        }
        int mod = 1e9 + 7;
        while(pq.size())
        {
            long long num = pq.top();
            
            product *= num;
            product = product %mod;
            pq.pop();
        }
        
        
        return product%mod;
        
    }
};