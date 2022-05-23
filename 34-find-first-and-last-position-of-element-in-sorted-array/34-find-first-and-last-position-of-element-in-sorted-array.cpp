class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int firstPos = -1 , lastPos = -1;
        
        int n = nums.size();
        
        int low = 0 , high = n-1;
        
        while(low <= high)
        {
            int mid = (low + high) /2;
            
            if(nums[mid]==target)
            {
                firstPos = mid;
                high = mid-1;
            }
            
            else if(nums[mid] <target)
                low =mid+1;
            else
                high = mid-1;
        }
        
        low = firstPos , high = n-1;
        
        if(low==-1)
            low = 0;
        
        while(low <= high)
        {
            int mid = (low + high)/2;
            
            if(nums[mid]==target)
            {
                lastPos = mid;
                low = mid+1;
            }
            
            else if(nums[mid] < target)
                low = mid+1;
            else 
                high = mid-1;
        }
        
        
        
        
        return {firstPos , lastPos};
        
    }
};