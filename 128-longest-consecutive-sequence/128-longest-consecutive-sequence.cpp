class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        set<int> st;
        
        for(auto it:nums)
            st.insert(it);
        
        int longestStreak = 0;
        
        for(auto it:st)
        {
            if(st.find(it-1) == st.end())
            {
                int currNum = it;
                int currStreak = 1;
                
                while(st.find(currNum+1) != st.end())
                {
                    currStreak++;
                    currNum++;
                }
                
                longestStreak = max(currStreak , longestStreak);
            }
        }
        
        return longestStreak;
        
    }
};