class Solution {
public:
    string getSmallestString(int n, int k) {
        
        string ans="";
        
        int len=n;
        while(n--)
        {
            for(int i=25;i>=0;i--)
            {
                char c=i+'a';
                int val=i+1;
                int currLen=ans.length()+1;
                if(k-val >=len-currLen)
                {
                    ans+=c;
                    k-=val;
                    break;
                }
            }
        }
        reverse(ans.begin() , ans.end());
        return ans;
        
    }
};