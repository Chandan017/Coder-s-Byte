class Solution {
public:
    int percentageLetter(string s, char letter) {
        
        int cnt =0;
        
        for(auto it:s)
            if(it==letter)
                cnt++;
        
        if(cnt==0)
            return 0;
        int n = s.length();
        
        return (cnt*100)/n;
        
    }
};