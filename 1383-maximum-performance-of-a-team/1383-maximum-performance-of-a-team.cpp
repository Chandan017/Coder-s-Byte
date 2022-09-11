class Solution {
public:    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        
        vector<pair<int,int>> engineers;
        
        for(int i=0;i<n;i++)
        {
            engineers.push_back({efficiency[i] , speed[i]});
        }
        
        sort(engineers.begin() , engineers.end() , greater<pair<int,int>>());
        priority_queue<int , vector<int> , greater<int>> pq;
        
        long res = 0 , speedSum = 0;
        
        for(auto &it:engineers)
        {
            pq.push(it.second);
            speedSum += it.second;
            
            if(pq.size() > k)
            {
                speedSum -= pq.top();
                pq.pop();
            }
            
            res = max(res , (speedSum * it.first));
        }
        
        int mod = 1e9+7;
        res %= mod;
        
        return res;
        
    }
};