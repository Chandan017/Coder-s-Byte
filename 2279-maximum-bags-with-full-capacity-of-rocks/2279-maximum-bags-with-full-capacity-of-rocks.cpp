class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        
        priority_queue<int,vector<int> , greater<int>> pq;
        
        for(int i=0;i<rocks.size();i++)
        {
            pq.push(capacity[i] - rocks[i]);
        }
        
        int cnt =0;
        
        while(additionalRocks > 0 && pq.size() > 0)
        {
            int curr = pq.top();
            pq.pop();
            
            if(curr==0)
            {
                cnt++;
                continue;
            }
            else if(curr <= additionalRocks)
            {
                
                additionalRocks -= curr;
                
                cnt++;
                continue;
            }
            
            else break;
                
        }
        
        return cnt;
    }
};