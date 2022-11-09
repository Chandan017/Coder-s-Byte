class StockSpanner {
public:
    
    stack<pair<int,int>> st;
    int currDay = 1;
    StockSpanner() {
        
    }
    
    int next(int price) {
        
       
        while(st.size() && st.top().first <= price)
            st.pop();
        
        int res = currDay;
        if(st.size())
        {
            res = currDay - st.top().second;
        }
        
        st.push({price , currDay});
        currDay++;
        
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */