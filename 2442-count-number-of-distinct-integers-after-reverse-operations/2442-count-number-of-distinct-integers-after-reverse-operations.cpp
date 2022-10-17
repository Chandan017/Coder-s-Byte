class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        
        unordered_set<int> st;
        
        for(auto it:nums)
        {
            st.insert(it);
            
            string curr = to_string(it);
            reverse(curr.begin() , curr.end());
            
            st.insert(stoi(curr));
        }
        
        
        return st.size();
        
    }
};