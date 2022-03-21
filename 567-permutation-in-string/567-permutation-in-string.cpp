class Solution {
public:
    bool check(int map1[] , int map2[])
    {
        for(int i=0;i<26;i++)
        {
            if(map1[i]!=map2[i])
                return false;
        }
        return true;
    }
   
    bool checkInclusion(string s1, string s2) {
        
        int n=s1.length() , m=s2.length();
        if(n>m )
            return false;
        
        int map1[26]={0};
        int map2[26]={0};
        
        for(int i=0;i<n;i++)
        {
             map1[s1[i]-'a']++;
             map2[s2[i]-'a']++;
        }
        map2[s2[n-1]-'a']--;
           
        for(int i=0;i<m-n+1;i++)
        {
            map2[s2[i+n-1]-'a']++;
            bool flag=check(map1,map2);
            
            if(flag)
                return true;
            
            map2[s2[i]-'a']--;
            
        }
        
        return false;
    }
};