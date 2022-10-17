class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        unordered_set<char> st;
        
        for(auto c:sentence)
            st.insert(c);
        
        return (st.size()==26);
        
    }
};