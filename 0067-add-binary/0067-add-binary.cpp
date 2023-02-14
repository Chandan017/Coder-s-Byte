class Solution {
public:
    string addBinary(string a, string b) {
        
        int i = a.length()-1 , j = b.length()-1;
        bool prev = false;
        
        string res = "";
        while(i>=0 || j>=0 || prev)
        {
           int curr = 0;
            if(prev)
            {
                prev = 0;
                curr++;
            }
            
            if(i>=0)
            {
                curr += (a[i]-'0');
                i--;
            }
            
            if(j>=0)
            {
                curr += (b[j]-'0');
                j--;
            }
            
            res += ((curr%2)+'0');
            if(curr/2)
                prev = true;
            
        }
        
        reverse(res.begin() , res.end());
        
        return res;
        
    }
};