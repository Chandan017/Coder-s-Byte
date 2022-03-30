class Solution {
public:
    int jump(vector<int>& nums) {
        
        int maxReach=0 , reach=0;
        int jumps=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(i > reach)
            {
                jumps++;
                reach=maxReach;
            }
            
            maxReach=max(maxReach ,nums[i] + i);
        }
        
        return jumps;
        
        
    }
};