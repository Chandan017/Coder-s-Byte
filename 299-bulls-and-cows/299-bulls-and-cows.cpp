class Solution {
public:
    string getHint(string secret, string guess) {
        
        int numBulls = 0 , numCows = 0;
        int guessMap[10] = {0};
        int n = secret.length();
        
        
        for(int i=0;i<n;i++)
        {
            if(secret[i] == guess[i])
                numBulls++;
            else
                guessMap[guess[i]-'0']++;
        }
        
        for(int i=0;i<n;i++)
        {
            if(secret[i] != guess[i])
            {
                if(guessMap[secret[i]-'0'] > 0)
                {
                    numCows++;
                    guessMap[secret[i]-'0']--;
                }
            }
        }
        
        string ans = to_string(numBulls) + 'A' + to_string(numCows) + 'B';
        
        
        return ans;
        
    }
};