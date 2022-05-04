class Solution {
public:
    int countPairs(vector<int>& nums) {
        
        unordered_map<int,int> mpp;
        long long cnt = 0;
        for(auto it:nums)
        {
            for(int i = 1;i<=pow(2,21);i*=2)
            {
                if(mpp.count(i-it))
                {
                    cnt += mpp[i-it];
                }
            }
            
            mpp[it]++;
        }
        
        int mod = 1e9 + 7;
        return cnt%mod;
    }
};