class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> freq;
        
        for(auto it:nums)
            freq[it]++;
        
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
        
        for(auto it:freq)
        {
            int val = it.first;
            int times = it.second;
            
            pq.push({times , val});
            
            if(pq.size() > k)
                pq.pop();
        }
        
        vector<int> ans(k) ;
        
        int ind = k-1;
        
        while(pq.size())
        {
            int val = pq.top().second;
            pq.pop();
            
            ans[ind] = val;
            ind--;
        }
        
        return ans;
        
        
    }
};