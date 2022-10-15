class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        map<string,int> mpp;
        int totalLen = 0 ;
        bool flag = true;
        for(auto it:words)
        {
            string original = it;
            reverse(it.begin() , it.end());
            
            if(mpp.find(it) != mpp.end() && mpp[it] > 0)
            {
                mpp[it]--;
                
                totalLen += 4;
            }
            else
                mpp[original]++;
        }
        
        int maxLen = 0;
        for(auto it:mpp)
        {
            string original = it.first;
            reverse(original.begin() , original.end());
            
            if(original[0] == original[1])
            {
                int currLen = it.second + it.second;
                
                maxLen = max(maxLen , currLen);
            }
            else if(original == it.first)
            {
                maxLen = max(maxLen , 2);
            }
            
            
        }
        
        totalLen += maxLen;
        return totalLen;
        
    }
};