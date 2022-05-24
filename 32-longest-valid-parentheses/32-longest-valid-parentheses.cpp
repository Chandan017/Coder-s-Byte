class Solution {
public:
    int longestValidParentheses(string s) {
        
        int maxLen = 0 ;
        
        int n = s.length();
        
        for(int i=0;i<n;i++)
        {
            int cnt = 0;
            
            for(int j=i;j<n;j++)
            {
                if(s[j]=='(')
                    cnt++;
                else
                    cnt--;
                
                if(cnt==0)
                {
                    int currLen = j-i+1;
                    
                    maxLen = max(currLen , maxLen);
                }
                
                if(cnt < 0)
                    break;
            }
        }
        
        return maxLen;
        
    }
};