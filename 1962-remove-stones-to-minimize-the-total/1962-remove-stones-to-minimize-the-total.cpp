class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        priority_queue<int> pq(piles.begin() , piles.end());
        
        while(k--)
        {
            int curr = pq.top()+1;
            pq.pop();
            pq.push(curr/2);
        }
        
        int res = 0;
        
        while(pq.size())
        {
            res += pq.top();
            pq.pop();
        }
        
        return res;
        
    }
};