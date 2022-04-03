class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n=temperatures.size();
        stack<int> st;
        vector<int> ans(n,0);
        
        for(int i=n-1;i>=0;i--)
        {
            while(st.size()>0 && temperatures[st.top()] <= temperatures[i])
                st.pop();
            
            if(st.size() > 0)
                ans[i]=(st.top() - i);
            
            st.push(i);
        }
        
        return ans;
    }
};