class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        
        int m = rolls.size() , currSum = accumulate(rolls.begin() , rolls.end(),0);
        vector<int> res;
        
        int need = mean*(n+m) - currSum;
        
        if(need > (n*6) || need < n)
            return res;
        
        for(int i=0;i<n;i++)
        {
            res.push_back(need/n);
        }
        
        if(need%n)
        {
            int rem = need%n;
            
            for(auto &it:res)
            {
                if(rem == 0)
                    break;
                
                int temp = min(rem , 6-it);
                it += temp;
                rem -= temp;
            }
        }
        
        
        
        return res;
        
    }
};