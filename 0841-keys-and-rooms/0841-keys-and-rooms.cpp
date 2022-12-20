class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        unordered_set<int> st;
        
        queue<int> q;
        q.push(0);
        st.insert(0);
        
        while(q.size())
        {
            int curr = q.front();
            q.pop();
            
            for(auto it:rooms[curr])
            {
                if(st.find(it) == st.end())
                {
                    st.insert(it);
                    q.push(it);
                }
            }
        }
        
        return (st.size() == rooms.size());
        
    }
};