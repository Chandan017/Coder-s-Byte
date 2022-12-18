class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        
        int res = 0 , n = arrays.size();
        int mini = arrays[0][0] , maxi = arrays[0][arrays[0].size()-1];
        
        for(int i=1;i<n;i++)
        {
            int currLen = arrays[i].size();
            
            res = max({res , abs(maxi-arrays[i][0]) , abs(arrays[i][currLen-1] - mini)});
            
            mini = min(mini , arrays[i][0]);
            maxi = max(maxi , arrays[i][currLen-1]);
        }
        
        return res;
        
        
        
    }
};