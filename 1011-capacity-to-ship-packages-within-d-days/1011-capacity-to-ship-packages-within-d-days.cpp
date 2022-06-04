class Solution {
public:
    
    bool solve(vector<int> &nums , int maxAllowed , int days)
    {
        int total = 0;
        int currDays = 1;
        
        for(int i=0;i<nums.size();i++)
        {
            if(total + nums[i] <= maxAllowed)
                total +=nums[i];
            else
            {
                currDays++;
                total = nums[i];
            }
            if(currDays > days || nums[i] > maxAllowed)
                    return false;
        }
        
        return true;
    }
    
    int shipWithinDays(vector<int>& nums, int days) {
        
            
        int low = *max_element(nums.begin() , nums.end());
        int high = accumulate(nums.begin() , nums.end(),0);
                
        int maxMin;
        
        while(low<=high)
        {
            int mid = (low+high)/2;
            bool isPossible = solve(nums , mid , days);
            
            if(isPossible==true)
            {
                maxMin = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        
        return maxMin;
        
        
    }
};