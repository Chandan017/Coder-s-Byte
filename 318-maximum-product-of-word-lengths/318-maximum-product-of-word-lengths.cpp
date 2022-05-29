class Solution {
public:
    
    int get(string &word)
    {
        int res = 0;
        
        for(auto &it:word)
        {
            int num = it-'a';
            num = 1<<num;
            res = res | num;
        }
        
        return res;
    }
    
    int maxProduct(vector<string>& words) {
        
        int maxLen = 0;
        int n = words.size();
        
        for(int i=0;i<n-1;i++)
        {
            int firstWord = get(words[i]);
    
            for(int j=i+1;j<n;j++)
            {
                int secondWord = get(words[j]);
                int res = firstWord & secondWord;
                if(res == 0)
                {
                    int firstLen = words[i].length();
                    int secondLen = words[j].length();
                    
                    int currLen = firstLen * secondLen;
                    maxLen = max(maxLen , currLen);
                }
            }
        }
        
        
        return maxLen;
        
    }
};