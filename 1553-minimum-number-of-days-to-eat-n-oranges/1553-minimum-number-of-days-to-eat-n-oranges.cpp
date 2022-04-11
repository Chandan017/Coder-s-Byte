class Solution {
public:
    
    int getMin(int n)
    {
        queue<int> q;
        
        q.push(n);
        int days = 0;
        while(!q.empty())
        {
            int size = q.size();
            set<int> st;
            while(size--)
            {
                int leftOranges = q.front();
                q.pop();
                     
                if(leftOranges < 0)
                    continue;
                if(leftOranges==0)
                    return days;
            
                st.insert(leftOranges - 1);
            
                if(leftOranges%2==0)
                {
                    int canEat = leftOranges / 2;
                
                    st.insert(leftOranges - canEat);
                }
            
                if(leftOranges % 3==0)
                {
                    int canEat = 2 * (leftOranges / 3);
                
                    st.insert(leftOranges - canEat );
                }
            }
            
            for(auto ele:st)
                q.push(ele);
            
            days++;
            
            
        }
        
        return days;
    }
    int minDays(int n) {
        
        int minDays = getMin(n);
        
        return minDays;
        
    }
};