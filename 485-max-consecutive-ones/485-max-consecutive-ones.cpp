class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        
        int maxOnes = 0 , runningOnes = 0;
        nums.push_back(0);
        int n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
                runningOnes++;
            else
            {
                maxOnes = max(maxOnes , runningOnes);
                runningOnes = 0;
            }
        }
        
        return maxOnes;
        
    }
};