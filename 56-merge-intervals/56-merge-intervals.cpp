class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin() , intervals.end());
        
        vector<vector<int>> ans;
        ans.push_back({intervals[0][0] , intervals[0][1]});
        
        int last=0;
        int n=intervals.size();
        for(int j=1;j<n;j++)
        {
            if(ans[last][1] >= intervals[j][0])
            {
                ans[last][1] = max(ans[last][1] , intervals[j][1]);
            }
            else
            {
                ans.push_back(intervals[j]);
                last++;
            }
        }
        
        return ans;
        
    }
};