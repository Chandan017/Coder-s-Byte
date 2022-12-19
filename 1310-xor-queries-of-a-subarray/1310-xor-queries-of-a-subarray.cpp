class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        vector<int> prefix;
        prefix.push_back(0);
        int prev = 0;
        for(auto it:arr)
        {
            prev ^= it;
            prefix.push_back(prev);
        }
        vector<int> res;
    
        for(auto it:queries)
        {
            int start = it[0] , end = it[1];

            int val = prefix[start] ^ prefix[end+1];
            res.push_back(val);
        }
        
        return res;
        
    }
};