class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        
        sort(intervals.begin() , intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int ind=0;
        int n=intervals.size();
        for(int i=1;i<n;i++)
        {
            if(ans[ind][1] >= intervals[i][0])
            {
                ans[ind][1] = max(intervals[i][1] , ans[ind][1]);
            }
            else
            {
                ans.push_back(intervals[i]);
                ind++;
            }
        }
        
        return ans;
    }
};