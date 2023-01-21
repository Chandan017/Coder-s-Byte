class Solution {
public:
    
    bool check(string s)
    {
        int n = s.length();
        if(n==1)
            return true;
        
        if(n>3 || s[0]=='0' || stoi(s) > 255)
            return false;
        
        return true;        
    }
    
    vector<string> restoreIpAddresses(string s) {
        
        int n = s.length();
        
        vector<string> res;
        
        if(n>12)
            return res;
        
        for(int i=1;i<=3;i++)
        {
            for(int j=1;j<=3;j++)
            {
                for(int k=1;k<=3;k++)
                {
                    if((i+j+k) < n && (i+j+k+3) >= n)
                    {
                        string a = s.substr(0,i);
                        string b = s.substr(i,j);
                        string c = s.substr(j+i , k);
                        string d = s.substr(i+j+k);
                        
                        if(check(a) && check(b) && check(c) && check(d))
                        {
                            string curr = a + '.' + b + '.' + c + '.' + d;
                            
                            res.push_back(curr);
                        }
                    }
                }
            }
        }
        
        
        return res;
        
    }
};