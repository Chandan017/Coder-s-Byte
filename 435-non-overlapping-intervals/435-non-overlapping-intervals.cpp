class Solution {
public:
    
    static bool comp(vector<int> &a , vector<int> &b)
    {
        return (a[1] < b[1]);
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin() , intervals.end() , comp);
        int n=intervals.size();
        int cnt=0;
        int prev=0;
        
        for(int i=1;i<n;i++)
        {
            if(intervals[prev][1] > intervals[i][0])
                cnt++;
            else
                prev=i;
        }
        
        return cnt;
        
    }
};