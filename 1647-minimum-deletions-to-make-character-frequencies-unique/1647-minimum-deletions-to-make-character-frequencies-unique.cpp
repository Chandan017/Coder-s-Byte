class Solution {
public:
    int minDeletions(string s) {
        
        vector<int> freq(26,0);
        
        for(auto it:s)
            freq[it-'a']++;
        
        set<int> st;
        
        int del = 0;
        for(auto it:freq)
        {
            if(it == 0 )
                continue;
            if(st.find(it) != st.end())
            {
                int val = it;
                
                while(val--)
                {
                    del++;
                    if(st.find(val) == st.end())
                    {
                        st.insert(val);
                        break;
                    }
                    
                }
            }
            
            else 
                st.insert(it);
        }
        
        return del;
        
    }
};