class MyCalendar {
public:
    vector<vector<int>> nums;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
                
        for(auto &it:nums)
        {
            if(start < it[1] && it[0] <end)
                return false;
        }
        
        nums.push_back({start , end});
        return true;
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */