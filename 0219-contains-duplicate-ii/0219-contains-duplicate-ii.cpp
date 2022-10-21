class Solution {
public:
    
   
        
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        unordered_map<int,int> mpp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(mpp.find(nums[i])!=mpp.end())
            {
                if(abs(mpp[nums[i]]-i) <=k)
                    return  true;
            }
            
            mpp[nums[i]]=i;
                
        }
        
     
        
        return false;
        
    }
};