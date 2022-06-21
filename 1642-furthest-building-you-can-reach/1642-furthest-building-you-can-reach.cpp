class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        priority_queue<int,vector<int> , greater<int>> pq;
        int n = heights.size();
        
        for(int i=0;i<n-1;i++)
        {
            if(heights[i+1] > heights[i])
            {
                if(pq.size() < ladders)
                    pq.push(heights[i+1] - heights[i]);
                else
                {
                    pq.push(heights[i+1] - heights[i]);
                    int lastMin = pq.top();
                    pq.pop();
                    
                    bricks -= lastMin;
                    
                }
                
                if(bricks < 0)
                    return i;
            }
        }
        
        return n-1;
        
    }
};