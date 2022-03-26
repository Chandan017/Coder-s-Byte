class MinStack {
public:
    stack<int> st;
    stack<int> supportingStack;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(supportingStack.size()==0 || (supportingStack.size() >0 && supportingStack.top() >= val))
            supportingStack.push(val);
        
    }
    
    void pop() {
        
        int val=st.top();
        if(supportingStack.top()==val)
            supportingStack.pop();
        
        st.pop();
    }
    
    int top() {
        
        return st.top();
    }
    
    int getMin() {
        
        return supportingStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */