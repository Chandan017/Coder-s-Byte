class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        
        map<int,vector<int>> mpp;
        int n = cards.size();
        
        for(int i=0;i<n;i++)
        {
            mpp[cards[i]].push_back(i);
        }
        
        int ans = INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            vector<int> &occurence = mpp[cards[i]];
            
            for(auto it:occurence)
            {
                if(it != i)
                {
                    int currSize = abs(it - i) + 1;
                
                    ans = min(currSize , ans);
                }
            }
            
        }
        
        if(ans == INT_MAX)
            ans = -1;
        return ans;
        
    }
};