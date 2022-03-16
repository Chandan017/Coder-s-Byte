class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        
        vector<bool> st(256,0);
        int n=s.length();
        int maxi=0 , i=0 , j=0;
        
        while(i<n && j<n)
        {
            if(st[s[j]]==0)
            {
                st[s[j]]=1;;
                j++;
                
                maxi=max(maxi , j-i);
            }
            else
            {
                st[s[i]]=0;
                i++;
            }
        }
        
        return maxi;
    }
};