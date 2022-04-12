class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        
        int totalGas = accumulate(gas.begin() , gas.end() , 0);
        int totalCost = accumulate(cost.begin() , cost.end() , 0);
        
        if(totalGas < totalCost)
            return -1;
        
        int n=gas.size();
        int left = 0 , finalInd = 0;
        for(int i=0;i<n;i++)
        {
            left += gas[i] - cost[i];
            
            if(left < 0)
            {
                left = 0;
                finalInd = i+1 ;
            }
        }
        
        return finalInd;
        
    }
};