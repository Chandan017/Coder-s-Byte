class Solution {
public:
    unordered_set<int> hasDay;
    
    int dp[366];
    
    int get(vector<int> &days , vector<int> &costs , int currDay)
    {
        if(currDay > 365)
            return 0;
        
        if(dp[currDay])
            return dp[currDay];
        
        int ans ;
        
        if(hasDay.find(currDay) != hasDay.end())
        {
            int oneDay = costs[0] + get(days , costs , currDay+1);
            int sevenDay = costs[1] + get(days , costs , currDay+7);
            int thirtyDay = costs[2] + get(days , costs , currDay+30);
            
            ans = min(oneDay , min(sevenDay , thirtyDay));
        }
        else
            ans = get(days , costs , currDay+1);
        
        return dp[currDay] = ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        for(auto it:days)
            hasDay.insert(it);
        
        int minCost = get(days , costs , 1);
        
        return minCost;
    }
};