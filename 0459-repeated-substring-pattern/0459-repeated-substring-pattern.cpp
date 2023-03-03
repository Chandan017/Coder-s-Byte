class Solution {
public:
    bool repeatedSubstringPattern(string s) {
       
        int n = s.length();
        string curr = s.substr(0 , n/2);
        int len = curr.length();
        while(len)
        {
            if(n%len == 0)
            {
                int times = n/len;
                string temp = "";
                while(times--)
                {
                    temp += curr;
                }
                if(temp == s)
                    return true;
            }
            len--;
            
            curr.pop_back();
        }
        cout<<endl;
        
        return false;
    }
};