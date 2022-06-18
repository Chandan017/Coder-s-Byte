class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int rightSum = accumulate(nums.begin() , nums.end() , 0);
        int leftSum = 0;
        int n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            //cout<<leftSum<<" "<<rightSum<<endl;
            rightSum -= nums[i];
            if(leftSum == rightSum)
                return i;
            
            leftSum += nums[i];
           
        }
        
        return -1;
        
    }
};