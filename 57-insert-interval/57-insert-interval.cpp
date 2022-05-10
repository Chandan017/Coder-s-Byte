class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        
        int leftInd=0;
        int n = intervals.size();
        for(int i=0;i<n;i++)
        {
            if(newInterval[0] >= intervals[i][0])
                leftInd = i+1;
        }
        
        intervals.insert(intervals.begin()+leftInd , newInterval);
        
        vector<vector<int>> ans;
        
        ans.push_back(intervals[0]);
        int currInd = 0;
        for(int i=1;i<n+1;i++)
        {
            if(intervals[i][0] <= ans[currInd][1])
            {
                ans[currInd][1] = max(ans[currInd][1] , intervals[i][1]);
            }
            else
            {
                ans.push_back(intervals[i]);
                currInd++;
            }
        }
        
        
        cout<<leftInd<<endl;
        
        return ans;
        
    }
};