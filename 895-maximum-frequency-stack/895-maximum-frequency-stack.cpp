class FreqStack {
    
private:
    priority_queue<pair<int,pair<int,int>>> pq;
    unordered_map<int,int> freq;
    int ind=-1;
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        ind++;
        freq[val]++;
        pq.push({freq[val] , {ind , val}});
        
        
    }
    
    int pop() {
        
        auto it=pq.top();
        pq.pop();
        int val=it.second.second;
        freq[val]--;
        
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */