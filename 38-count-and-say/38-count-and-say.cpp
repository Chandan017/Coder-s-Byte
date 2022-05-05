class Solution {
public:
    
    string get(int n)
    {
        if(n==1)
            return "1";
        
        int times = 0;
        
        string temp = get(n-1);
        temp += '0';
        char val = temp[0];
    
        string ans = "";
        
        for(auto it:temp)
        {
            if(it==val)
                times++;
            else
            {
                ans += (times+'0');
                ans += val;
                val = it;
                times = 1;
            }
        }
    
        return ans;
    }
    
    string countAndSay(int n) {
        
        string ans = get(n);
        
        return ans;
        
    }
};