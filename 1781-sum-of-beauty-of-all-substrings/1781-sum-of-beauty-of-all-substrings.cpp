class Solution {
public:
    
    int getBeauty(unordered_map<char,int> &mpp)
    {
        int maxi = INT_MIN , mini = INT_MAX;
        
        for(auto &it:mpp)
        {
            maxi = max(maxi , it.second);
            mini = min(mini , it.second);
        }
        
        return maxi-mini;
    }
    int beautySum(string s) {
        
        int res = 0 , n = s.length();
        
        
        for(int i=0;i<n;i++)
        {
            unordered_map<char,int> freq;
            for(int j=i;j<n;j++)
            {
                freq[s[j]]++;
                
                if(freq.size() > 1)
                {
                    int currBeauty = getBeauty(freq);
                    
                    res += currBeauty;
                }
            }
        }
        
        return res;
    }
};