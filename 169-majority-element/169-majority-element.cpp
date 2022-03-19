class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int cnt=0 , maj=0;
        
        
        for(auto &it:nums)
        {
            if(cnt==0)
                maj=it;
            
            cnt+=(it==maj?1:-1);
        }
        return maj;
        
    }
};