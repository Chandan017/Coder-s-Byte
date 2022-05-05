class Solution {
public:
    
    int compress(vector<char>& chars) {
        
        
        char val = chars[0];
        int times = 0;
        int cnt = 0;
        int ind = 0;
        for(auto it:chars)
        {
            if(it==val)
                times++;
            else
            {
                cnt++;
                chars[ind] = val;
                ind++;
                if(times >1)
                {
                   string temp = to_string(times);
                    for(auto j:temp)
                    {
                        chars[ind] = j;
                        ind++;
                        cnt++;
                    }
                }
                
                times = 1;
                val = it;
            }
        }
        
        cnt++;
        chars[ind] = val;
        ind++;
        if(times >1)
        {
            string temp = to_string(times);
            for(auto j:temp)
            {
                chars[ind] = j;
                ind++;
                cnt++;
            }
        }
        
        return cnt;
    }
};