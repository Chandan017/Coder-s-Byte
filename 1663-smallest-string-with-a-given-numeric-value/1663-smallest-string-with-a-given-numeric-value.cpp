class Solution {
public:
    string getSmallestString(int n, int k) {
        
        string ans(n,'a');
        
        k=k-n;
        
        while(n>0 && k>0)
        {
            int mini=min(25 , k);
            ans[--n]=mini+'a';
            k-=mini;
        }
        
        
        return ans;
        
    }
};