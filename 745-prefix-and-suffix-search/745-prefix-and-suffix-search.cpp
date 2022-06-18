class WordFilter {
public:
    
    map<string,int> mpp;
    
    WordFilter(vector<string>& words) {
        
        int n = words.size();
        
        for(int i=0;i<n;i++)
        {
            string word = words[i];
            
            int wordLen = word.length();
            
            for(int j=1;j<=wordLen;j++)
            {
                string pre = word.substr(0,j);
                
                for(int k=0;k<wordLen;k++)
                {
                    string suff = word.substr(k,wordLen);
                    
                    mpp[pre + "," + suff] = i+1;
                }
            }
        }
        
    }
    
    int f(string prefix, string suffix) {
        
        string word = prefix + "," + suffix;
        return mpp[word] - 1;
        
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */