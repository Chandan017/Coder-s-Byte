class Solution {
public:
    int calculate(string s) {
        
        stack<int> op;
        op.push(1);
        
        int total = 0 , num = 0 , isPositive = 1;
        
        for(auto c:s)
        {
            if(isdigit(c))
                num = num*10 + (c-'0');
            else
            {
                total += num * isPositive * op.top();
                num = 0;
                
                if(c == '+')
                    isPositive = 1;
                else if(c == '-')
                    isPositive = -1;
                
                else if(c == ')')
                    op.pop();
                else if(c == '(')
                {
                    op.push(op.top() * isPositive);
                    isPositive = 1;
                }
            }
        }
        
        total += num*isPositive*op.top();
        
        return total;
        
    }
};