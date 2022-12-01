class Solution {
public:
    bool isVowel(char c)
    {
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U');
    }
    bool halvesAreAlike(string s) {
        
        int n = s.length();
        int mid = n/2;
        
        int i=0 , firstHalf = 0 , secondHalf = 0;
        while(i<mid)
        {
            if(isVowel(s[i]))
                firstHalf++;
            i++;
        }
        
        while(i<n)
        {
            if(isVowel(s[i]))
                secondHalf++;
            i++;
        }
        
        return (firstHalf == secondHalf);
    }
};