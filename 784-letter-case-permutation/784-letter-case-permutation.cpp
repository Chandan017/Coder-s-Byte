class Solution {
public:
    
    vector<string> ans;
    void get(string &s , int ind ,int n, string temp)
    {
        if(ind==n)
        {
            ans.push_back(temp);
            return ;
        }
        
        if(isdigit(s[ind]))
        {
            temp+=s[ind];
            get(s,ind+1,n,temp);
        }
        else
        {
            string curr1=temp;
            curr1.push_back(tolower(s[ind]));
            get(s,ind+1,n,curr1);
            
            string curr2=temp;
            curr2+=toupper(s[ind]);
            
            get(s,ind+1,n,curr2);
        }
        
        return ;
    }
    vector<string> letterCasePermutation(string s) {
        int n=s.length();
        get(s,0,n,"");
        
        return ans;
    }
};