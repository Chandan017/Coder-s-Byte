class Solution {
public:
    
    static bool comp(vector<int> &a , vector<int> &b)
    {
        return (a[1] < b[1]);
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin() , intervals.end() , comp);
        int n=intervals.size();
        int cnt=-1;
        vector<int> prev=intervals[0];
        
        for(auto &it:intervals)
        {
            if(prev[1] > it[0])
                cnt++;
            else
                prev=it;
        }
        
        return cnt;
        
    }
};