class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size() , maxRange = 0 , currRange = 0 , jumps = 0;
        
        for(int i=0;i<n;i++)
        {
            if(maxRange < i)
            {
                jumps++;
                maxRange = currRange;
            }
            
            currRange = max(currRange , i + nums[i]);
        }
        
        return jumps;
        
    }
};