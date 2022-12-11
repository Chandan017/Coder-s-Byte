class Solution {
public:
    
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        sort(intervals.begin() , intervals.end());
        
        priority_queue<int,vector<int> , greater<int>> minEndTime;
        
        minEndTime.push(intervals[0][1]);
        int rooms = 1 ;
        
        for(int i=1;i<intervals.size();i++)
        {
            int minTime = minEndTime.top();
                
            if(intervals[i][0] < minTime)
                rooms++;
            else
                minEndTime.pop();
            minEndTime.push(intervals[i][1]);
        }
        
        return rooms;
    }
};