class Solution {
public:

    int connectSticks(vector<int>& sticks) {
        
        priority_queue<int , vector<int> , greater<int>> pq;
        int n = sticks.size();
        
        for(int i=0;i<n;i++)
        {
            pq.push(sticks[i]);
        }
        
        int minCost = 0;
        
       while(pq.size() > 1)
       {
           int cost = pq.top();
           pq.pop();
           cost += pq.top();
           pq.pop();
           
           minCost += cost;
           pq.push(cost);
       }
        
        return minCost;
        
    }
};