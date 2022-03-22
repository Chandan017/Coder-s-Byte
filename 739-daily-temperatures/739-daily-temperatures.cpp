class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        stack<int> st;
        vector<int> ans;
        
        int n=temperatures.size();
        
        for(int i=n-1;i>=0;i--)
        {
            if(st.size()==0)
                ans.push_back(0);
            else if(st.size()>0 && temperatures[st.top()]>temperatures[i])
                ans.push_back(st.top()-i);
            else if(st.size()>0 && temperatures[st.top()]<=temperatures[i])
            {
                while(st.size()>0 && temperatures[st.top()]<=temperatures[i])
                    st.pop();
                if(st.size()==0)
                    ans.push_back(0);
                else 
                    ans.push_back(st.top()-i);
            }
            
            st.push(i);
            
        }
        
        reverse(ans.begin() , ans.end());
        return ans;
        
    }
};