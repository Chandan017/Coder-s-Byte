class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        int cnt = 0;
        
        unordered_map<long,long> mpp;
        mpp[0]=1;
        long sum = 0;
        
        for(int i=0;i<n;i++)
        {
            sum += nums[i];
            
            long rem = sum%k;
            
            if(rem < 0 )
                rem += k;
            
            cnt += mpp[rem];
            
            mpp[rem]++;
        }
        
        return cnt;
        
    }
};