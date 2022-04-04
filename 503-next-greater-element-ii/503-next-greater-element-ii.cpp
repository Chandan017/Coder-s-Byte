class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n=nums.size();
        stack<int> st;
        vector<int> ans(n,-1);
        int newSize=2*n-1;
        for(int i=newSize;i>=0;i--)
        {
            while(st.size()>0 && st.top()<=nums[i%n])
                st.pop();
            
            if(i<n && st.size()>0)
                ans[i]=st.top();
            
            st.push(nums[i%n]);
                
        }
        
        return ans;
        
    }
};