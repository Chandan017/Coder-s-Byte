class Solution {
public:
    
    string countAndSay(int n) {
        
        if(n == 1)
            return "1";
        
        string res = "1";
        
        for(int i=2;i<=n;i++)
        {
            char prev = res[0] ;
            int freq = 0 , len = res.length();
            string curr = "";
            for(int i=0;i<=len;i++)
            {
                if(prev != res[i] || i == len)
                {
                    curr += to_string(freq);
                    curr += prev;
                    prev = res[i];
                    freq = 1;
                }
                else
                    freq++;
            }
            
            
            res = curr;
        }
        
        return res;
        
    }
};