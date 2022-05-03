class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        vector<int> dup = nums;
        
        sort(dup.begin() , dup.end());
        int n=nums.size() , first = 0 , second = 0;
        for(int i=0;i<n;i++)
        {
            if(dup[i] != nums[i])
            {
                first = i;
                break;
            }
        }
        
        for(int i=n-1;i>=0;i--)
        {
            if(dup[i] != nums[i])
            {
                second = i;
                break;
            }
        }
        
        if(first==second)
            return 0;
        
        return abs(first-second)+1;
        
    }
};