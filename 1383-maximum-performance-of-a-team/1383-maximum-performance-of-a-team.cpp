class Solution {
public:
    int len ;
    long long ans = INT_MIN;
    void solve(vector<int> &speed , vector<int> &efficiency , int ind , int k , long long mini , long long sum)
    {        
        long long curr = sum*mini;
        ans = max(ans , curr);
        
        if(ind == len || k==0)
            return ;
        
        solve(speed , efficiency , ind+1 , k-1 , min(mini ,(long long)efficiency[ind]) , sum+speed[ind]);
        solve(speed , efficiency , ind+1 , k , mini , sum);
        
        return ;
    }
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        
        vector<pair<int,int>> engineers;
        
        for(int i=0;i<n;i++)
        {
            engineers.push_back({efficiency[i] , speed[i]});
        }
        
        sort(engineers.begin() , engineers.end() , greater<pair<int,int>>());
        priority_queue<int , vector<int> , greater<int>> pq;
        
        long res = 0 , speedSum = 0;
        
        for(auto it:engineers)
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