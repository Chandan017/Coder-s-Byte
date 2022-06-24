class Solution {
public:
    bool isPossible(vector<int>& target) {
        
        priority_queue<int> pq;
        int n = target.size();
        long sum = 0;
        
        if(n==1)
            return target[0]==1;
        
        for(auto it:target)
        {
            pq.push(it);
            sum += it;
        }
        
        while(pq.top() != 1)
        {
            int currMax = pq.top();
            pq.pop();
            
            if(sum - currMax == 1)
                return true;
            
            int currVal = currMax % (sum - currMax);
            sum = sum - currMax + currVal;
            
            if(currVal == 0 || currVal == currMax )
                return false;
            pq.push(currVal);
        }
        
        return true;
        
    }
};