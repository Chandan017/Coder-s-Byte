class Solution {
public:
    
    int getRightInterval(vector<vector<int>> &startIntervals , int endInterval , int currInd)
    {
        
        int l = 0 , h = startIntervals.size()-1;
        int res = INT_MAX;

        while(l<=h)
        {
            int mid = l+(h-l)/2;
            // cout<<mid<<" ";
            // if(startIntervals[mid][0] == endInterval && startIntervals[mid][1] != currInd)
            //     return startIntervals[mid][1];
            if(startIntervals[mid][0] >= endInterval)
            {
                h = mid-1;
                res = min(res , startIntervals[mid][1]);
            }
            else
            {
                l = mid+1;
            }
        }
        
        
        if(res == INT_MAX)
            return -1;
        
        return res;
    }
    
    
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        
        
        vector<vector<int>> startIntervals;
        int n = intervals.size();
        
        for(int i=0;i<n;i++)
        {
            startIntervals.push_back({intervals[i][0] , i});
        }
        
        sort(startIntervals.begin() , startIntervals.end());
        
        // for(auto it:startIntervals)
        //     cout<<it[0]<<" ";
        // cout<<endl;
        vector<int> res;
        
        for(int i=0;i<n;i++)
        {
            int rightInd = getRightInterval(startIntervals , intervals[i][1] , i);
            // cout<<endl;
            res.push_back(rightInd);
        }
        
        
        return res;
        
    }
};