class Solution {
public:
    
    
    vector<int> numsSameConsecDiff(int n, int k) {
        
        vector<int> ans;
        if(n==1)
        {
            for(int i=0;i<=n;i++)
                ans.push_back(i);
            
            return ans;
        }
        
        queue<int> q;
        
        for(int i=1;i<=9;i++)
            q.push(i);
        
        int totalLength=1;
        while(totalLength!=n)
        {
            int size=q.size();
            while(size--)
            {
                int top=q.front();
                q.pop();
                int lastDigit=top%10;
                
                if(lastDigit+k<10)
                    q.push(top*10 + lastDigit+k);
                
                if(k!=0 && lastDigit-k >=0)
                    q.push(top*10 + lastDigit-k);
                
            }
            
            totalLength++;
            
        }
        
        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        
        return ans;
            
        
    }
};