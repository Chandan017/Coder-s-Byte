class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size() , i = 1 , j = 1;
        
        while(i<n)
        {
            if(nums[i] != nums[i-1])
            {
                nums[j] = nums[i];
                j++;
            }
                i++;
        }
        
        return j;
        
    }
};