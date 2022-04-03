class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        
        int n=nums.size() , k,l;
        
        if(n==0 || n==1)
            return ;
        
       for(k=n-2;k>=0;k--)
       {
           if(nums[k] < nums[k+1])
               break;
       }
        
        if(k>=0)
        {
            for(l=n-1;l>=0;l--)
            {
                if(nums[l] > nums[k])
                    break;
            }
            
            swap(nums[k] , nums[l]);
        }
        
        reverse(nums.begin()+k+1 , nums.end());
            
    }
};