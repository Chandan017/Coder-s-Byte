class Solution {
public:
    int halveArray(vector<int>& nums) {
        
        double totalSum = 0.00;
        priority_queue<double> pq;
        for(auto it:nums)
        {
            totalSum += it;
            pq.push(it);
        }
        
        int cnt = 0;
        
        double halfSum = totalSum / 2.00;
        double reducedSum = 0.00;
        while(reducedSum < halfSum)
        {
            double val = pq.top();
            pq.pop();
            val = val / 2.00;
            
            reducedSum += val;
            pq.push(val);
            
            cnt++;
        }
        
        
        return cnt;
    }
};