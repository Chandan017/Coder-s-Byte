class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        vector<int> a(26,0) , b(26,0);
        
        for(auto it:s1)
            a[it-'a']++;
        
        int m = s1.length();
        for(int i=0;i<s2.length();i++)
        {
            b[s2[i]-'a']++;
            
            if(i >= m-1)
            {
                // for(auto it:b)
                //     cout<<it<<" ";
                // cout<<endl;
                if(a == b)
                    return true;
                
                b[s2[i-m+1]-'a']--;
            }
        }
        
        
        return false;
    }
};