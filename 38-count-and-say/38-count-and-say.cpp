class Solution {
public:
    
   
    string countAndSay(int n) {
        
        string ans = "1";
        
        for(int i=2;i<=n;i++)
        {
            string dummy = "";
            char val = ans[0];
            int times = 0;
            ans += '0';
            
            for(auto it:ans)
            {
                if(it==val)
                    times++;
                else
                {
                    dummy += (times + '0');
                    dummy += val;
                    val = it;
                    times = 1;
                }
            }
            
            ans = dummy;
        }
        return ans;
        
    }
};