class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        
        vector<int> ans;
        int n=heights.size();
        
        stack<int> st;
        
        for(int i=n-1;i>=0;i--)
        {
            if(st.size()==0)
                ans.push_back(0);
            else if(st.size()>0 && st.top()>=heights[i])
                ans.push_back(1);
            else if(st.size()>0 && st.top()<heights[i])
            {
                int cnt=0;
                while(st.size()>0 && st.top()<heights[i])
                {
                    st.pop();
                    cnt++;
                }
                if(st.size()==0)
                    ans.push_back(cnt);
                else
                    ans.push_back(cnt+1);
            }
            
            st.push(heights[i]);
        }
        
        reverse(ans.begin() , ans.end());
        
        return ans;
        
    }
};