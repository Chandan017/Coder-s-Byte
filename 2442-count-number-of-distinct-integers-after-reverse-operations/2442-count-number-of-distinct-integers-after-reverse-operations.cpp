class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        
        unordered_set<int> st;
        
        for(auto it:nums)
        {
            st.insert(it);
            int currNum = 0;
            
            while(it)
            {
                currNum = (currNum*10) + (it%10);
                it /= 10;
            }
            st.insert(currNum);
        }
        
        
        return st.size();
        
    }
};