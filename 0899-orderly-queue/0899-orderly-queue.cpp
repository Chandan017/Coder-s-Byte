class Solution {
public:
    string orderlyQueue(string s, int k) {
        
        if(k==1)
        {
            string res = s;
            
            for(int i=0;i<s.length();i++)
            {
                char first = s[0];
                
                s.erase(s.begin());
                
                s += first;
                
                res = min(res , s);
            }
            
            return res;
        }
        
        sort(s.begin() , s.end());
        
        return s;
        
    }
};