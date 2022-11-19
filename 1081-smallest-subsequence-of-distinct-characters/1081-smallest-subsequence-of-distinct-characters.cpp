class Solution {
public:
    string smallestSubsequence(string s) {
        
        
        vector<int> freq(26,0);
        vector<bool> taken(26,false);
        
        for(auto it:s)
            freq[it-'a']++;
        
        stack<char> st;
        
        for(auto ch:s)
        {
            freq[ch-'a']--;
            
            if(taken[ch-'a'])
                continue;
            
            while(st.size() && st.top() > ch && freq[st.top()-'a'] > 0)
            {
                taken[st.top()-'a'] = false;
                st.pop();
            }
            
            taken[ch-'a'] = true;
            
            st.push(ch);
        }
        
        string res = "";
        while(st.size())
        {
            res += st.top();
            st.pop();
        }
        
        reverse(res.begin() , res.end());
        
        return res;
        
        
        
    }
};