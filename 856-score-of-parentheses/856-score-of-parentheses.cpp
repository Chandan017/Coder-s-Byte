class Solution {
public:
    int scoreOfParentheses(string s) {
     
        
        int ans=0, dep=0;
        
        int n=s.length();
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
                dep++;
            else
            {
                dep--;
                if(s[i-1]=='(')
                    ans+=(1<<dep);
            }
        }
        return ans;
    }
};