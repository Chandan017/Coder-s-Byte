class Solution {
public:
    vector<int> getNSR(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> st;
        vector<int> nsr(n);
        for(int i=n-1;i>=0;i--)
        {
            while(st.size() && nums[st.top()] >= nums[i])
                st.pop();
            
            if(st.size())
                nsr[i] = st.top()-i;
            else
                nsr[i] = n-i;
            st.push(i);
        }
        
        return nsr;
    }
    
    vector<int> getNSL(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> st;
        vector<int> nsl(n);
        
        for(int i=0;i<n;i++)
        {
            while(st.size() && nums[st.top()] > nums[i])
                st.pop();
            
            if(st.size())
                nsl[i] = i-st.top();
            else
                nsl[i] = i+1;
            
            st.push(i);
        }
        return nsl;
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        
        vector<int> nsr = getNSR(arr);
        vector<int> nsl = getNSL(arr);
        long res = 0;
        int mod = 1e9+7 , n = arr.size();
        
        
        for(int i=0;i<n;i++)
        {
            long times = (nsl[i] * nsr[i]) % mod;
            long currMin = (times * arr[i]) % mod;
            
            res  = (res + currMin) % mod;
        }
        
        return res;
        
        
        
    }
};