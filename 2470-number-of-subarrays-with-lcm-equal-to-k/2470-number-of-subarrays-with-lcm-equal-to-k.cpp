class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        
        int n = nums.size() , cnt = 0;
        
        for(int i=0;i<n;i++)
        {
            long curr = 1;
            for(int j=i;j<n;j++)
            {
                curr = lcm(curr , nums[j]);
                
                if(curr == k)
                    cnt++;
                else if(curr > k)
                    break;
            }
        }
        
        return cnt;
        
    }
};