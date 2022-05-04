class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        map<int,int> mpp;
        int cnt = 0;
        for(auto it:nums)
        {
            int res = k - it;
            
            if(mpp.find(res) != mpp.end() && mpp[res] > 0)
            {
                cnt++;
                mpp[res]--;
            }
            else
                mpp[it]++;
        }
        
        return cnt;
    }
};