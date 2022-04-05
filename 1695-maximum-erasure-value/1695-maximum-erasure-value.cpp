class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int n=nums.size() , maxSum = 0 , currSum = 0 , left=0;
        
        set<int> st;
        
        for(int i=0;i<n;i++)
        {
            
            while(st.find(nums[i]) != st.end())
            {
                st.erase(nums[left]);
                currSum -= nums[left];
                left++;
            }
            
            currSum += nums[i];
            st.insert(nums[i]);
            
            maxSum = max(maxSum , currSum);
        }
        
        return maxSum ;
        
    }
};