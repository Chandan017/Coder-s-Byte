class Solution {
public:
    int longestValidParentheses(string s) {
        
        
        int n = s.length();
        int maxLen =0;
        for(int i=0;i<n;i++)
        {
            int cnt =0;
            for(int j=i;j<n;j++)
            {
                if(s[j]=='(')
                    cnt++;
                else
                    cnt--;
                
                if(cnt <0)
                    break;
                
                if(cnt==0)
                {
                    int currLen = j-i+1;
                    
                    maxLen = max(maxLen , currLen);
                    
                    if(maxLen > n-i+1)
                        return maxLen;
                }
            }
        }
        
        return maxLen;
        
    }
};