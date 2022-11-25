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
            
            if(!st.size())
            {
                nsr[i] = n-i;
            }
            else
                nsr[i] = st.top()-i;
            
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
            
            if(!st.size())
            {
                nsl[i] = i+1;
            }
            else
                nsl[i] = i-st.top();
            
            
            st.push(i);
        }
        return nsl;
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        
        vector<int> nsr = getNSR(arr);
        vector<int> nsl = getNSL(arr);
        long res = 0;
        int mod = 1e9+7 , n = arr.size();
        
//         for(int i=0;i<n;i++)
//         {
//             int mini = arr[i];
            
//             for(int j=i;j<n;j++)
//             {
//                 mini = min(mini , arr[j]);
//                 cout<<mini<<" ";
//             }
            
//             cout<<endl;
//         }
//         cout<<endl;
        
        // for(auto it:nsl)
        //     cout<<it<<" ";
        // cout<<endl;
        // for(auto it:nsr)
        //     cout<<it<<" ";
        // cout<<endl;
        
    
        
        for(int i=0;i<n;i++)
        {
            long cnt = nsl[i]*nsr[i];
            
            // cout<<cnt<<" ";
            
            cnt = (cnt*arr[i])%mod;
            
            res  = (res + cnt)%mod;
        }
        
        return res;
//         for(auto it:nsl)
//             cout<<it<<" ";
//         cout<<endl;
        
//         return 1;
        
        
        
    }
};