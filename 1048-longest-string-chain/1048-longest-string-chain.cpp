class Solution {
public:
    
    static bool comp(string &a , string &b)
    {
        return a.length() < b.length();
    }
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin() , words.end() , comp);
        
        map<string,int> mpp;
        int res = 1;
        
        for(auto &word:words)
        {
            mpp[word] = 1;
            for(int i=0;i<word.length();i++)
            {
                string prev = word.substr(0,i) + word.substr(i+1);
                
                if(mpp.find(prev) != mpp.end())
                {
                    mpp[word] = mpp[prev]+1;
                    res = max(res , mpp[word]);
                }
            }
        }
        
        return res;
    }
};