class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        sort(potions.begin() , potions.end());
        int m = potions.size();
        vector<int> ans;
        
        for(auto s:spells)
        {
            int l = 0 , r = m-1;
            int res = m;
            while(l<=r)
            {
                int mid = (l+r)/2;
                long prod = 1LL * potions[mid] * s;
                
                if(prod >=success)
                {
                    res = mid;
                    r = mid -1;
                }
                else
                    l = mid+1;
            }
            ans.push_back(m-res);
        }
        
        return ans;
       
        
    }
};