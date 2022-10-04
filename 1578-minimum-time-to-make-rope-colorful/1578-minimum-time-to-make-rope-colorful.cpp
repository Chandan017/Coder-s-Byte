class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int totalCost = 0;
        
        int i=0, j=0 , n = colors.size();
        
        while(i<n)
        {
            int maxCost = 0 , currTotal = 0;
            
            while(j<n && colors[j] == colors[i])
            {
                maxCost = max(maxCost , neededTime[j]);
                currTotal += neededTime[j];
                j++;
            }
           
            currTotal -= maxCost;
            totalCost += currTotal;
            
            i = j;
        }
        
        return totalCost;
    }
};