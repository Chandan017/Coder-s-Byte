class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        
        
        unordered_map<int,int> mpp;
        
        for(auto it:tasks)
            mpp[it]++;
        
        int cnt = 0;
        
        for(auto it:mpp)
        {
            if(it.second == 1)
                return -1;
            
            cnt += (it.second/3);
            
            if(it.second%3 != 0)
                cnt++;
        }
        
        return cnt;
        
    }
};