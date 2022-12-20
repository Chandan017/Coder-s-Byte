class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        
        int i = 0 , n = sentence1.size() , m = sentence2.size();
        
        if(n != m)
            return false;
        
        set<vector<string>> st;
        for(auto it:similarPairs)
        {
            st.insert({it[0] , it[1]});
            st.insert({it[1] , it[0]});

        }
        
        while(i<n)
        {
            if(sentence1[i] != sentence2[i])
            {
                if(st.find({sentence1[i] , sentence2[i]}) != st.end() || st.find({sentence2[i] , sentence1[i]}) != st.end())
                {
                    i++;
                    continue;
                }
                else
                    return false;
            }
            i++;
        }
        
        return true;
        
    }
};