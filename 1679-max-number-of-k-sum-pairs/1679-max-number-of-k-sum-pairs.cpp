class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        sort(nums.begin() , nums.end());
        
        int start = 0 , end = nums.size()-1;
        int cnt = 0;
        
        while(start < end)
        {
            int sum = nums[start] + nums[end];
            
            if(sum == k)
            {
                cnt++;
                start++;
                end--;
            }
            else if(sum < k)
                start++;
            else
                end--;
        }
        
        return cnt;
    }
};