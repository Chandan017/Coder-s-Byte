class Solution {
public:
    
    string countAndSay(int n) {
        
        if(n == 1)
            return "1";
        
        string curr = countAndSay(n-1);
        
        string res = "";
        char prev = curr[0];
        int freq = 0 , len = curr.length();
        for(int i=0;i<=len;i++)
        {
            if(curr[i] != prev || i == len)
            {
                res += (to_string(freq));
                
                res += prev;
                
                if(i != len)
                    prev = curr[i];
                freq = 1;
            }
            else
                freq++;
        }
        
        
        return res;
        
    }
};