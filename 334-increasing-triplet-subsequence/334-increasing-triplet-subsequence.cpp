class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        
        int n=nums.size();
        if(n<3)
            return false;
        
        vector<int> prefixMini(n,INT_MAX);
        vector<int> suffixMaxi(n , INT_MIN);
        
        for(int i=0;i<n;i++)
        {
            if(i==0)
                prefixMini[i]=nums[i];
            else
                prefixMini[i]=min( nums[i] , prefixMini[i-1]);    
        }
        
        suffixMaxi[n-1]=nums[n-1];
       for(int i=n-2;i>=0;i--)
       {
           suffixMaxi[i]=max(nums[i] , suffixMaxi[i+1]);
               
       }
        
        
        for(int i=1;i<n-1;i++)
        {
            int low=prefixMini[i-1];
            int high=suffixMaxi[i+1];
            
            if(nums[i] > low && nums[i] < high)
                return true;
        }
        return false;
    }
};