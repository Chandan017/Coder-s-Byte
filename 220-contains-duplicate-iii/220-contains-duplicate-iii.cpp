class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        
        int n = nums.size();
        
        vector<pair<long,long>> v;
        
        for(int i=0;i<n;i++)
        {
            v.push_back({nums[i] , i});
        }
        
        sort(v.begin() , v.end());
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                long diff = abs(v[i].first - v[j].first);
                
                if(diff<=t)
                {
                    if(abs(v[i].second - v[j].second) <=k)
                        return true;
                }
                else
                    break;
            }
        }
        
        
        return false;
        
    }
};