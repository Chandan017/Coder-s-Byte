class Solution {
public:
    
    string match(string &s1 , string &s2)
    {
        int n1=s1.length() , n2 = s2.length();
        
        int ind = 0;
        string ans = "";
        
        while(ind<n1 && ind<n2)
        {
            if(s1[ind]!=s2[ind])
                break;
            else
            {
                ans += s1[ind];
                ind++;
            }
        }
        
        return ans;
        
    }
    
    
    string longestCommonPrefix(vector<string>& strs) {
        
        int n = strs.size();
        
        if(n==1)
            return strs[0];
        
        string temp = match(strs[0] , strs[1]);
        
        for(int i=2;i<n;i++)
        {
            string curr = match(temp , strs[i]);
            temp = curr;
        }
        
        return temp;
        
        
    }
};