class Solution {
public:
    void reverseWords(vector<char>& s) {
    
        
        reverse(s.begin() , s.end());
        
        int l = 0 , r = 0 , n = s.size();
        while(l<n)
        {
            r = l;
            while(r+1<n && s[r+1] != ' ')
            {
                r++;
            }
            
            int prev = r;
            
            while(l<r)
            {
                swap(s[l] , s[r]);
                l++;
                r--;
            }
            l = prev+2;
        }
        return ;
        
    }
};