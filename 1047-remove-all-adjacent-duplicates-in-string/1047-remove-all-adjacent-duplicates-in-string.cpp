class Solution {
public:
    string removeDuplicates(string s) {
        
        string ans="";
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(ans.size() >0 && ans.back()==s[i])
                ans.pop_back();
            else
                ans+=s[i];
        }
               
        return ans;
    }
};