class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        
        
        unordered_map<char,int> mpp;
        int prev = 0 , maxLen = 0;
        int n = s.length();
        
        for(int i=0;i<n;i++)
        {
            mpp[s[i]]++;
            
            if(mpp.size() <= k)
            {
                int currLen = i-prev+1;
                maxLen = max(maxLen , currLen);
            }
            else
            {
                while(prev<i && mpp.size() > k)
                {
                    mpp[s[prev]]--;
                    if(mpp[s[prev]] == 0)
                        mpp.erase(s[prev]);
                    prev++;
                }
            }
        }
        
        return maxLen;
    }
};