class Solution {
public:
    int longestPalindrome(string s) {
        
        int n=s.length();
        if(n==1)
            return 1;
        
        map<char,int> mpp;
        for(auto it:s)
            mpp[it]++;
        
        int cnt=0;
        bool hasOdd=false;
        for(auto &it:mpp)
        {
            if(it.second%2==0)
                cnt+=it.second;
            
            else {
                if(hasOdd==false)
                {
                    hasOdd=true;
                    cnt+=it.second;
                }
                else
                    cnt+=it.second -1;
            }
        }
        
        return cnt;
        
    }
};