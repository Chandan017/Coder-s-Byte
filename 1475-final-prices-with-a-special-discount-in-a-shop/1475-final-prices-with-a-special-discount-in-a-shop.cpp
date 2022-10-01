class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        
        int n = prices.size();
        stack<int> st;
        
        for(int i=n-1;i>=0;i--)
        {
            while(st.size() && st.top() > prices[i])
                st.pop();
            
            int val = prices[i];
            
            if(st.size())
                prices[i] -= st.top();
            
            prices[i] = max(prices[i] , 0);
            
            st.push(val);
        }
        
        return prices;
        
    }
};