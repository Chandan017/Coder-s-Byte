class Solution {
public:
    string baseNeg2(int n) {
        
        string ans="";
        if(n==0)
            return (to_string(n));
        while(n)
        {
            int rem=n%(-2);
            n/=(-2);
            
            if(rem<0)
            {
                rem+=2;
                n+=1;
            }
            ans+=(to_string(rem));
        }
        reverse(ans.begin() , ans.end());
        return ans;
        
    }
};