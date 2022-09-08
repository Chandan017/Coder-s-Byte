class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size() , i = 1 , j = 0;
        
        while(i<n)
        {
            if(nums[i]==nums[i-1])
                i++;
            else
            {
                nums[j+1] = nums[i];
                j++;
                i++;
            }
        }
        
        for(auto it:nums)
            cout<<it<<" ";
        cout<<endl;
        
        return j+1;
        
    }
};