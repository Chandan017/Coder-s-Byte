class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        long long res = 0 , minPos = -1 , maxPos = -1 , left = -1;
        int n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            if(nums[i] < minK || nums[i] > maxK)
                left = i;
            if(nums[i] == minK)
                minPos = i;
            if(nums[i] == maxK)
                maxPos = i;
            
            long long curr = min(minPos , maxPos) - left;
            if(curr < 0)
                curr = 0;
            res += curr;
            cout<<res<<" ";
        }
        
        cout<<endl;
        
        return res;
        
    }
};