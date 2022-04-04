class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        
        
        int n=heights.size();
        vector<int> ans(n);
        
        
        stack<int> st;
        
        for(int i=n-1;i>=0;i--)
        {
            int cnt=0;
            while(st.size()>0 && st.top()<heights[i])
            {
                st.pop();
                cnt++;
            }
            
            if(st.size()==0)
                ans[i]=cnt;
            else
                ans[i]=cnt+1;
            st.push(heights[i]);
        }
            
        return ans;
        
    }
};