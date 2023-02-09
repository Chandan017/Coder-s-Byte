class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long res = 0;
        vector<unordered_set<string>> temp(26);
        
        for(auto it:ideas)
            temp[it[0]-'a'].insert(it.substr(1));
        
        for(int i=0;i<26;i++)
        {
            for(int j=i+1;j<26;j++)
            {
                unordered_set<string> curr(temp[i].begin() , temp[i].end());
                curr.insert(temp[j].begin() , temp[j].end());
                
                res += ((temp[i].size() - curr.size()) * (temp[j].size() - curr.size()));
            }
        }
        
        res *= 2;
        return res;
    }
};