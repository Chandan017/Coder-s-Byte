class Solution {
public:
    
    bool isSame(int map1[] , int map2[])
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
        
        int map1[26]={0};
        
        for(int i=0;i<n;i++)
            map1[s1[i]-'a']++;
        
        for(int i=0;i<m-n+1;i++)
        {
            int map2[26]={0};
            
            for(int j=0;j<n;j++)
                map2[s2[i+j]-'a']++;
            
            if(isSame(map1 , map2)==true)
                return true;
        }
        
        return false;
    }
};