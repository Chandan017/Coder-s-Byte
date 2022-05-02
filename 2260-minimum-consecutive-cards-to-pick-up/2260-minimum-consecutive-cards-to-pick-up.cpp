class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        
        vector<int> last(1000001 , -1);
        
        int n = cards.size();
        
        int ans = INT_MAX;
        
        
        for(int i=0;i<n;i++)
        {
            if(last[cards[i]]  != -1)
            {
                int currSize = i - last[cards[i]] + 1;
                
                ans = min(currSize , ans);
                cout<<currSize<<" ";
            }
            
            last[cards[i]] = i;
        }
        
        if(ans == INT_MAX)
            ans = -1;
        
        return ans;
        
    }
};