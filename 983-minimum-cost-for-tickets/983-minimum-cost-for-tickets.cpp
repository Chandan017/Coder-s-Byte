class Solution {
public:
    
    unordered_set<int> hasDays;
    int dp[366];
    int minCost(vector<int> &days , vector<int> &costs , int currDay )
    {
        if(currDay > 365)
            return 0;
        
        if(dp[currDay])
            return dp[currDay];
        
        int totalCost;
        
        if(hasDays.find(currDay) != hasDays.end())
        {
            int oneDay = costs[0] + minCost(days , costs , currDay+1);
            int sevenDay = costs[1] + minCost(days , costs , currDay+7);
            int thirtyDay = costs[2] + minCost(days , costs , currDay+30);
            
            totalCost = min(oneDay , min(sevenDay , thirtyDay));
        }
        else
            totalCost = minCost(days , costs, currDay+1 );
        
        return dp[currDay] = totalCost;
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        
        for(auto it:days)
            hasDays.insert(it);
        
        int totalCost = minCost(days , costs , 1 );
        
        return totalCost;
        
    }
};