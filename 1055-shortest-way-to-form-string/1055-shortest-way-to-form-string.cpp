class Solution {
public:
    int shortestWay(string source, string target) {
        
        int res = 0 , t=0;
        
        while(t<target.length())
        {
            int dupT = t;
            
            for(auto it:source)
            {
                if(t<target.length() && target[t] == it)
                    t++;
            }
            
            if(t == dupT)
                return -1;
            
            res++;
        }
        
        return res;
        
    }
};