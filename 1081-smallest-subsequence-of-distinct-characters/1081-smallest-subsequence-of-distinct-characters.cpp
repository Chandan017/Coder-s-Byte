class Solution {
public:
    string smallestSubsequence(string s) {
        
        
        vector<int> freq(26,0);
        vector<bool> taken(26,false);
        
        for(auto it:s)
            freq[it-'a']++;
        
        stack<int> st;
        
        for(auto ch:s)
        {
            freq[ch-'a']--;
            
            if(taken[ch-'a'])
                continue;
            
            while(st.size() && (st.top()+'a') > ch && freq[st.top()] > 0)
            {
                taken[st.top()] = false;
                st.pop();
            }
            
            taken[ch-'a'] = true;
            
            st.push(ch-'a');
        }
        
        string res = "";
        while(st.size())
        {
            res += (st.top()+'a');
            st.pop();
        }
        
        reverse(res.begin() , res.end());
        
        return res;
        
        
        
    }
};