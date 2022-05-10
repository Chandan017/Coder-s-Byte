class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        
        int n = intervals.size();
        int currInd = 0;
        vector<vector<int>> ans;
        
        while(currInd < n && intervals[currInd][1] < newInterval[0])
        {
            ans.push_back(intervals[currInd]);
            currInd++;
        }
        
        while(currInd < n && intervals[currInd][0] <= newInterval[1])
        {
            newInterval[0] = min(intervals[currInd][0] , newInterval[0]);
            newInterval[1] = max(intervals[currInd][1] , newInterval[1]);
            
            currInd++;
        }
        
        
        ans.push_back(newInterval);
        
        while(currInd < n)
        {
            ans.push_back(intervals[currInd]);
            currInd++;
        }
        
        
        
        return ans;
        
    }
};