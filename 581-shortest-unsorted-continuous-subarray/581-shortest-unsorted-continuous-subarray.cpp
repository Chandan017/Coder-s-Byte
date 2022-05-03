class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        stack<int> st;
        int n = nums.size() , first = n, second = 0;
        
        for(int i=0;i<n;i++)
        {
            while(st.size() > 0 && nums[st.top()] > nums[i])
            {
                int ind = st.top();
                first = min(first , ind);
                st.pop();
            }
            
            st.push(i);
        }
        
        while(st.size())
            st.pop();
        
        for(int i=n-1;i>=0;i--)
        {
            while(st.size() > 0 && nums[st.top()] < nums[i])
            {
                int ind = st.top();
                st.pop();
                second = max(second , ind);
            }
            
            st.push(i);
        }
        
        
        
        if(second - first < 0)
            return 0;
        return second-first + 1;
        
        
    }
};