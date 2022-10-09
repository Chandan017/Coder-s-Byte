class Solution {
public:
    vector<int> lexicalOrder(int n) {
        
        vector<string> curr;
        
        for(int i=1;i<=n;i++)
            curr.push_back(to_string(i));
        
        sort(curr.begin() , curr.end());
        
        vector<int> res;
        
        for(auto it:curr)
        {
            res.push_back(stoi(it));
        }
        
        return res;
        
    }
};