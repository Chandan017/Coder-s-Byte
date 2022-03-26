class StockSpanner {
public:
    stack<pair<int,int>> st;
    int ind=-1;
    int prev=-1;
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        ind++;
        
        if(prev!=-1)
            st.push({prev , ind-1});
        
        prev=price;
        
        while(st.size() >0 && st.top().first <=price)
            st.pop();
        
        if(st.size()==0)
            return (ind - (-1));
        return (ind - (st.top().second));
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */