class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        
        int maxRange = 0 , n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            if(maxRange < i)
                return false;
            
            int currRange = i + nums[i];
            
            maxRange = max(maxRange , currRange);
            
            if(maxRange >= n-1)
                return true;
        }
        
        return false;
        
    }
};