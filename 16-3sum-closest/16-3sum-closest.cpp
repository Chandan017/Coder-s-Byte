class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
                
        int n = nums.size();
        
        sort(nums.begin() , nums.end());
        
        int closest = nums[0] + nums[1] + nums[2];
        
        for(int i=0;i<n-2;i++)
        {
            
            int first = i;
            
            int second = i+1 , third = n-1;
            
            while(second<third)
            {
                int currSum = nums[first] + nums[second] + nums[third];
                
                if(currSum == target)
                    return currSum;
                
                if(abs(target-currSum) < abs(target-closest))
                    closest = currSum;
                
                if(currSum < target)
                    second++;
                else
                    third--;
                    
            }
        }
        
      
        return closest;
    }
};