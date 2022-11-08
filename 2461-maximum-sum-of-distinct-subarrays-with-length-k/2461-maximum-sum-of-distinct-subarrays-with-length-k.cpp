class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        int n = nums.size()  , prev = 0 ;
        long long sum = 0 , maxSum = 0;
        unordered_set<long long> st;
        
        for(int i=0;i<n;i++)
        {
            if(st.find(nums[i]) == st.end())
            {
                st.insert(nums[i]);
                sum += nums[i];
            }
            else
            {
                while(prev<n && st.find(nums[i]) != st.end())
                {
                    sum -= nums[prev];
                    st.erase(st.find(nums[prev]));
                    prev++;
                    
                }
                
                st.insert(nums[i]);
                sum+= nums[i];
            }
            
            if(i-prev == k-1)
            {
                maxSum = max(sum , maxSum);
                
                sum -= nums[prev];
                st.erase(st.find(nums[prev]));
                prev++;
                // cout<<maxSum<<" ";
            }
        }
        
        // cout<<endl;
        
        return maxSum;
        
    }
};