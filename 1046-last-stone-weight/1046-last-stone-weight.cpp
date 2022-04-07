class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> pq;
        
        for(auto &it:stones)
            pq.push(it);
                
        while(pq.size() > 0)
        {
            int first = pq.top();
            pq.pop();
            
            if(pq.size() == 0)
                return first;
            
            int second = pq.top();
            pq.pop();
            
            if(first != second)
            {
                int remain = abs(first - second);
                pq.push(remain);
            }
        }
        
       return 0;
    }
};