class Solution {
public:
    bool isOperator(string &st)
    {
        return (st=="/" || st=="+" || st=="-" || st=="*");
    }
    int evalRPN(vector<string>& tokens) {
        
        stack<int> st;
        for(auto it:tokens)
        {
            if(isOperator(it))
            {
                long secondNum = st.top();
                st.pop();
                long firstNum = st.top();
                st.pop();
                long total = 0;
                
                if(it == "+")
                    total = firstNum + secondNum;
                else if(it =="*")
                    total = firstNum * secondNum;
                else if(it == "-")
                    total = firstNum - secondNum;
                else 
                    total = firstNum/secondNum;
                
                
                // cout<<firstNum<<"->"<<secondNum<<"->"<<total<<"   ";
                st.push(total);
            }
            else
                st.push(stoi(it));
        }
        
        // cout<<endl;
        return st.top();
        
    }
};