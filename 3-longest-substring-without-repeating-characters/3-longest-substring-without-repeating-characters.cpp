class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        
        unordered_set<char> st;
        int n=s.length();
        int maxi=0 , i=0 , j=0;
        
        while(i<n && j<n)
        {
            if(st.find(s[j])==st.end())
            {
                st.insert(s[j]);
                j++;
                
                maxi=max(maxi , j-i);
            }
            else
            {
                st.erase(s[i]);
                i++;
            }
        }
        
        return maxi;
    }
};