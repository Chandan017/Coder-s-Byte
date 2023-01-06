class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        
        sort(costs.begin() , costs.end());
        int cnt = 0;
        for(auto it:costs)
        {
            if(it <= coins)
            {
                cnt++;
                coins -= it;
            }
            else
                break;
        }
        
        return cnt;
        
    }
};