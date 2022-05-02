class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        
        int maxElement = *max_element(cards.begin() , cards.end());
        vector<int> last(maxElement+1 , -1);
        
        int n = cards.size();
        
        int ans = INT_MAX;
        
        
        for(int i=0;i<n;i++)
        {
            if(last[cards[i]]  != -1)
            {
                int currSize = i - last[cards[i]] + 1;
                
                ans = min(currSize , ans);
            }
            
            last[cards[i]] = i;
        }
        
        if(ans == INT_MAX)
            ans = -1;
        
        return ans;
        
    }
};