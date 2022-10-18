class Solution {
public:
    int compress(vector<char>& chars) {
        
        chars.push_back('A');
        int totalLen = 0 , freq = 0 , n = chars.size() , prevInd = 0;
        char prev = chars[0];
        
        for(int i=0;i<n;i++)
        {
            if(chars[i] != prev)
            {
                totalLen++;
                chars[prevInd] = prev;
                prevInd++;
                if(freq != 1)
                {
                    string freqCopy = to_string(freq);
                    for(auto it:freqCopy)
                    {
                        chars[prevInd] = it;
                        prevInd++;
                        totalLen++;
                    }
                }                
                prev = chars[i];
                freq = 1;
            }
            else
                freq++;
        }
        chars.pop_back();
        return totalLen;
        
    }
};