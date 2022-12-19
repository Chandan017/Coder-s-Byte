class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        
        int n = nums.size() , cnt = 0;
        
        sort(nums.begin() , nums.end());
        for(int i=0;i<n-2;i++)
        {
            int l = i+1 , h = n-1;
            int currTarget = target - nums[i];
            while(l < h)
            {
                int sum = nums[l] + nums[h];
                
                if(sum < currTarget)
                {
                    cnt += (h-l);
                    l++;
                }
                else
                    h--;
            }
        }
        
        return cnt;
        
    }
};