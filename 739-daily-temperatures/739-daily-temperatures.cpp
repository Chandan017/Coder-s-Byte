class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        stack<int> st;
        int n=temperatures.size();
        vector<int> ans(n,0);
        
        
        
        for(int i=n-1;i>=0;i--)
        {
            if(st.size()==0)
                ans[i]=(0);
            else if(st.size()>0 && temperatures[st.top()]>temperatures[i])
                ans[i]=(st.top()-i);
            else if(st.size()>0 && temperatures[st.top()]<=temperatures[i])
            {
                while(st.size()>0 && temperatures[st.top()]<=temperatures[i])
                    st.pop();
                if(st.size()==0)
                    ans[i]=(0);
                else 
                    ans[i]=(st.top()-i);
            }
            
            st.push(i);
            
        }
        
        
        return ans;
        
    }
};