class Solution {
    
#define ps pair<int,string>
public:
    
    bool comp(ps &s1 , ps &s2)
    {
        if(s1.first==s2.first)
            return s1.second < s2.second;
        
        return s1.first > s2.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        priority_queue<ps> pq;
        
        map<string , int> mpp;
        
        for(auto &it:words)
        {
            mpp[it]++;
        }
        
        for(auto &it:mpp)
        {
            pq.push({-it.second , it.first});
            
            if(pq.size() > k)
                pq.pop();
        }
        
        vector<string> ans(k);
        int j=k-1;
        
        while(!pq.empty())
        {
            ans[j]=pq.top().second;
            pq.pop();
            j--;
        }
        
        return ans;
        
    }
};