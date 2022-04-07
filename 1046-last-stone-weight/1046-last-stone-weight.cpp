class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> pq;
        
        for(auto &it:stones)
            pq.push(it);
        
        int ans=0;
        
        while(pq.size() > 1)
        {
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            
            if(first != second)
            {
                int remain = abs(first - second);
                pq.push(remain);
            }
        }
        
        if(pq.size() > 0)
            ans = pq.top();        
        return ans;
    }
};