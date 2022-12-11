class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        
        unordered_map<char,int> mpp;
        int prev = 0 , maxLen = 0;
        
        for(int i=0;i<s.length();i++)
        {
            mpp[s[i]]++;
            
            if(mpp.size() <= 2)
            {
                int currLen = i-prev+1;
                maxLen = max(maxLen , currLen);
            }
            else
            {
                while(prev<i && mpp.size()>2)
                {
                    mpp[s[prev]]--;
                    
                    if(mpp[s[prev]] == 0)
                        mpp.erase(s[prev]);
                    prev++;
                }
            }
        }
        cout<<endl;
        return maxLen;
        
    }
};