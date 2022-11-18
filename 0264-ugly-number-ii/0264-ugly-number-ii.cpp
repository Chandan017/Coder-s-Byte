class Solution {
public:
    int nthUglyNumber(int n) {
        
        if(n==1)
            return 1;
        priority_queue<long,vector<long> , greater<long>> pq;
        
        pq.push(1);
        
        int cnt = 1;
        unordered_set<long> vis;
        while(pq.size())
        {
            long curr = pq.top();
            pq.pop();
            
            if(cnt == n)
                return curr;
            
            if(vis.find(curr*2) == vis.end())
            {
                pq.push(curr*2);
                vis.insert(curr*2);
            }
            if(vis.find(curr*3) == vis.end())
            {
                pq.push(curr*3);
                vis.insert(curr*3);
            }
            if(vis.find(curr*5) == vis.end())
            {
                pq.push(curr*5);
                vis.insert(curr*5);
            }
            cnt++;
        }
        
        return -1;
        
    }
};