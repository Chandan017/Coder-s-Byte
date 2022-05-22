class Solution {
public:
    
    int cnt =0;
    
    bool check(string &s)
    {
        if(s.length()==0)
            return false;
        int l=0 , r=s.length()-1;
        
        while(l<r)
        {
            if(s[l] != s[r])
                return false;
            l++;
            r--;
        }
        
        return true;
    }
  
    
    int countSubstrings(string s) {
        
       
        int n = s.length();
        
        for(int i=0;i<n;i++)
        {
            string temp = "";
            for(int j=i;j<n;j++)
            {
                temp += s[j];
                
                if(check(temp))
                    cnt++;
            }
        }
        return cnt;
        
    }
};