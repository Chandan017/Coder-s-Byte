class WordDistance {
public:
    unordered_map<string,vector<int>> mpp;
    
    WordDistance(vector<string>& wordsDict) {
        
        for(int i=0;i<wordsDict.size();i++)
            mpp[wordsDict[i]].push_back(i);
        
    }
    
    int shortest(string word1, string word2) {
        
        int minLen = INT_MAX;
    
        for(auto &i:mpp[word1])
        {
            for(auto &j:mpp[word2])
            {
                minLen = min(minLen , abs(i-j));
            }
        }
        
        return minLen;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */