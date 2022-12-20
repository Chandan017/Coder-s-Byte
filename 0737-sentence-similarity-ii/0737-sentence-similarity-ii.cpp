class Solution {
public:
    map<string,set<string>> mpp;
    
    bool check(string &src , string &dest , set<string> &vis)
    {
        
        if(src == dest)
            return true;
        vis.insert(src);

        for(auto it:mpp[src])
        {
            if(vis.find(it) == vis.end())
            {
                if(check(it , dest , vis))
                    return true;
            }
        }
        
        return false;
    }

    
    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        
        
        int n = sentence1.size() , m = sentence2.size() , i =0;
        if(n != m)
            return false;
        
        for(auto it:similarPairs)
        {
            mpp[it[0]].insert(it[1]);
            mpp[it[1]].insert(it[0]);
        }
        
        
        while(i<n)
        {
            if(sentence1[i] != sentence2[i])
            {
                set<string> vis;
                bool curr = check(sentence1[i] , sentence2[i] , vis);
                
                if(!curr)
                    return false;
            }
            i++;
                
        }
        
        return true;
        
        
        
    }
};