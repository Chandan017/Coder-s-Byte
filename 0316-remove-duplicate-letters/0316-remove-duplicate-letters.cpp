class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        vector<int> freq(26,0); 
        vector<bool> isTaken(26,false);
        
        for(auto it:s)
            freq[it-'a']++;
        
        string res = "";
        
        for(auto it:s)
        {
            freq[it-'a']--;
            
            if(isTaken[it-'a'])
                continue;
            
            while(res.length() && res.back() > it && freq[res.back()-'a'])
            {
                isTaken[res.back()-'a'] = false;
                res.pop_back();
            }
            
            isTaken[it-'a'] = true;
            
            res += it;
        }
        
        return res;
        
    }
};