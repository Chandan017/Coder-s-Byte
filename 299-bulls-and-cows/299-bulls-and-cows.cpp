class Solution {
public:
    string getHint(string secret, string guess) {
        
        int numBulls = 0 , numCows = 0;
        map<char,int> guessMap;
        int n = secret.length();
        
        
        for(int i=0;i<n;i++)
        {
            if(secret[i] == guess[i])
                numBulls++;
            else
                guessMap[guess[i]]++;
        }
        
        for(int i=0;i<n;i++)
        {
            if(secret[i] != guess[i])
            {
                if(guessMap.find(secret[i]) != guessMap.end() && guessMap[secret[i]] > 0)
                {
                    numCows++;
                    guessMap[secret[i]]--;
                }
            }
        }
        
        string ans = to_string(numBulls) + 'A' + to_string(numCows) + 'B';
        
        
        return ans;
        
    }
};