class Solution {
public:
        
    string longestPalindrome(string s) {
        
        int n = s.length();
        if(n<=1)
            return s;
        string res = "";
        for(int i=0;i<n-1;i++)
        {
            string temp = "";
            for(int j=i;j<n;j++)
            {
                temp += s[j];
                
                if(temp.length() > res.length())
                {
                    int l = 0 , h = temp.length()-1;
                    bool flag = true;
                    
                    while(l<h)
                    {
                        if(temp[l] != temp[h])
                        {
                            flag = false;
                            break;
                        }
                        l++;
                        h--;
                    }
                    
                    if(flag)
                        res = temp;
                }
            }
            
            if(res.length()==n)
                return res;
        }
        
        return res;
        
    }
};