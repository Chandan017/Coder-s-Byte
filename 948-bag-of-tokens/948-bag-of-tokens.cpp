class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        
        int n = tokens.size();
        sort(tokens.begin() , tokens.end());
        
        int maxScore = 0 , currScore = 0;
        int i = 0 , j = n-1;
        while(i<=j)
        {
            if(power >= tokens[i])
            {
                power -= tokens[i];
                currScore++;
                i++;
            }
            else if(currScore >= 1)
            {
                currScore--;
                power += tokens[j];
                j--;
            }
            else 
                break;
            maxScore = max(maxScore , currScore);
        }
        
       
        
        return maxScore;
        
        
    }
};