class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int totalGas = accumulate(gas.begin() , gas.end() , 0);
        int totalCost = accumulate(cost.begin() , cost.end() , 0);
        
        if(totalCost > totalGas)
            return -1;
        
        
        int leftGas = 0 , finalIndex = 0;
        
        for(int i=0;i<gas.size();i++)
        {
            leftGas += gas[i] - cost[i];
            
            if(leftGas < 0)
            {
                leftGas = 0;
                finalIndex = i+1;
            }
        }
        
        return finalIndex;
        
    }
};