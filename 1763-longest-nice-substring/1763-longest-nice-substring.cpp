class Solution {
public:
    
    bool isNice(int smallCase[] , int capitalCase[])
    {
        
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
            int smallCase[26] = {0}  , capitalCase[26] = {0};
            
            for(int j=i;j<n;j++)
            {
                temp += s[j];
                if(islower(s[j]))
                    smallCase[s[j]-'a']++;
                else
                    capitalCase[s[j]-'A']++;
                
                if(isNice(smallCase , capitalCase) && temp.length() > res.length() )
                    res = temp;
            }
        }
        
        return res;
        
    }
};