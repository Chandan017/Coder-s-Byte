class Solution {
public:
    int countSegments(string s) {
        
        int cnt = 0;
        bool prev = false;
        for(auto it:s)
        {
            if(it == ' ')
            {
                if(prev)
                    cnt++;
                prev = false;
            }
            else
            {
                prev = true;
            }
        }
        
        if(prev)
            cnt++;
        
        return cnt;
    }
};