class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
       
        int n = nums.size();
        int first = -1 , second = 0;
        
        while(second < n)
        {
            if(nums[second]%2==0)
            {
                first++;
                swap(nums[second] , nums[first]);
            }
            second++;
        }
        return nums;
        
    }
};