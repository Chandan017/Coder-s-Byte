class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        
        int n = wordsDict.size() , word1Ind = -1 , word2Ind = -1;
        int minDist = INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            if(wordsDict[i] == word1)
            {
                word1Ind = i;
            }
            else if(wordsDict[i] == word2)
            {
                word2Ind = i;
            }
            
            if(word1Ind != -1 && word2Ind != -1)
            {
                minDist = min(minDist , abs(word2Ind - word1Ind));
            }
        }
        
        return minDist;
    }
};