class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        int n=pushed.size();
        int popInd=0;
        
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            st.push(pushed[i]);
            
            if(st.top()==popped[popInd])
            {
                while(st.size() >0 && st.top()==popped[popInd])
                {
                    st.pop();
                    popInd++;
                }
            }
        }
        
        
        return st.empty();
        
    }
};