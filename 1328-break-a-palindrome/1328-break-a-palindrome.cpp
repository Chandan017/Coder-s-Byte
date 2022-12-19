class Solution {
public:
    string breakPalindrome(string palindrome) {
        
        int n = palindrome.length();
        
        if(n==1)
            return "";
        
        string temp = palindrome;
        int i = 0;
        
        while(i<n && palindrome[i] == 'a')
            i++;
        
        if(i<n)
            palindrome[i] = 'a';
        
        int j = 0;
        while(j<n && palindrome[j] == 'a')
            j++;
        
        if(j==n)
        {
            temp[n-1] = 'b';
            palindrome = temp;
        }
        
        return palindrome;
    }
};