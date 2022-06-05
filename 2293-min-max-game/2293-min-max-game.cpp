class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        
        
        while(nums.size()!=1)
        {
            vector<int> temp;
            bool flag = true;
            for(int i=0;i<nums.size()-1;i+=2)
            {
                if(flag)
                {
                    int mini = min(nums[i] , nums[i+1]);
                    temp.push_back(mini);
                    flag = false;
                }
                else
                {
                    int maxi = max(nums[i] , nums[i+1]);
                    temp.push_back(maxi);
                    flag = true;
                }
                
            }
            
            
            nums = temp;
        }
        
        return nums[0];
        
    }
};