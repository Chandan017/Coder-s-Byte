class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        
        map<string,int> mpp;
        int minDist = INT_MAX , n = wordsDict.size();
        
        for(int i=0;i<n;i++)
        {
            if(wordsDict[i] == word1)
            {
                if(mpp.find(word2) != mpp.end())
                {
                    minDist = min(minDist , abs(i - mpp[word2]));
                }
                
                mpp[word1] = i;
            }
            
            else if(wordsDict[i] == word2)
            {
                if(mpp.find(word1) != mpp.end())
                {
                    minDist = min(minDist , abs(i-mpp[word1]));
                }
                
                mpp[word2] = i;
            }
            
        }
        
        return minDist;
        
    }
};