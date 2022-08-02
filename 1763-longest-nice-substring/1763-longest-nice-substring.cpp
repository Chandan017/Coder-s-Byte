class Solution {
public:
    
    bool isNice(string &t)
    {
        int smallCase[26] = {0}  , capitalCase[26] = {0};
        
        for(auto it:t)
        {
            if(islower(it))
                smallCase[it-'a']++;
            else
                capitalCase[it-'A']++;
        }
        
        for(int i=0;i<26;i++)
        {
            if((smallCase[i] > 0 && capitalCase[i] == 0) || (smallCase[i]==0 && capitalCase[i] > 0))
                return false;
        }
        
        return true;
    }
    
    
    string longestNiceSubstring(string s) {
        
        int n = s.length();
        
        string res = "";
        
        for(int i=0;i<n;i++)
        {
            string temp = "";
            
            for(int j=i;j<n;j++)
            {
                temp += s[j];
                
                if(isNice(temp) && temp.length() > res.length() )
                    res = temp;
            }
        }
        
        return res;
        
    }
};