class Solution {
public:
    int n;
    
    bool isPossible(vector<int> &nums , int val , int k)
    {
        int i = 0;
        
        while(i<n)
        {
            if(nums[i] <= val)
            {
                i += 2;
                k--;
            }
            else
                i++;
        }
        
        return (k<=0);
    }
    
    int minCapability(vector<int>& nums, int k) {
        
        n = nums.size();
        int l = 0 , r = *max_element(nums.begin() , nums.end());
        while(l<r)
        {
            int mid = (l+r)/2;
            
            if(isPossible(nums , mid , k))
                r = mid;
            else
                l = mid+1;
        }
        
        return r;
    }
};