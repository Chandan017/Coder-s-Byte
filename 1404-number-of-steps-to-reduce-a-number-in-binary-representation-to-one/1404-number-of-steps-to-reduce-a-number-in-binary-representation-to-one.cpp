class Solution {
public:
    void addOne(string &s)
    {
        int n = s.length();
        for(int i=n-1;i>=0;i--)
        {
            if(s[i] == '1')
            {
                s[i] = '0';
            }
            else
            {
                s[i] = '1';
                return ;
            }
        }
        
        s.insert(s.begin() , '1');
        
        return ;
    }
    int numSteps(string s) {
        
        int cnt = 0;
        while(s.length() > 1)
        {
            if(s.back() == '0')
                s.pop_back();
            else
            {
                addOne(s);
            }
            
            
            cnt++;
        }
        
        return cnt;
        
    }
};