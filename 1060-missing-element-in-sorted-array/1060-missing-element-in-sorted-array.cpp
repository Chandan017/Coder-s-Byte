class Solution {
public:
    int missing(int ind , vector<int> &nums)
    {
        return (nums[ind]-nums[0]-ind);
    }
    int missingElement(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        if(k> missing(n-1 , nums))
            return nums[n-1] + k - missing(n-1 , nums);
        
        int low = 0 , high = n-1;
        
        while(low < high)
        {
            int mid = low + (high-low)/2;
            
            if(missing(mid , nums) < k)
                low = mid+1;
            else
                high = mid;
        }
        
        int res = nums[low-1] + k - missing(low-1 , nums);
        
        return res;
        
    }
};