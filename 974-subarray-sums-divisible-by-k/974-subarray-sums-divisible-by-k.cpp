class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int cnt = 0;
        
        unordered_map<long,long> mpp;
        mpp[0] = 1;
        
        long sum = 0;
        
        for(auto it:nums)
        {
            sum += it;
            
            long rem = sum%k;
            if(rem < 0)
                rem += k;
            
            cnt += mpp[rem];
            mpp[rem]++;
        }
        
        return cnt;
        
    }
};