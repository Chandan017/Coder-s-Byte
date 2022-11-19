class Solution {
public:

    bool isPalindrome(string &s)
    {
        int l = 0 , h = s.length()-1;

        while(l<h)
        {
            if(s[l] != s[h])
                return false;
            l++;
            h--;
        }

        return true;
    }
    
    bool checkPalindromeFormation(string a, string b) {

        int n = a.length();

        if(isPalindrome(a) || isPalindrome(b))
            return true;
        int i=0,j=n-1;

        while(i<n && j>=0)
        {
            if(a[i] == b[j])
            {
                i++;
                j--;
            }
            else
                break;
        }

        if(i>=j)
            return true;
        
        
        string temp1 = b.substr(i , j-i+1);
        string temp2 = a.substr(i , j-i+1);
        
        if(isPalindrome(temp1) || isPalindrome(temp2))
            return true;
        
        i=0,j=n-1;

        while(i<n && j>=0)
        {
            if(b[i] == a[j])
            {
                i++;
                j--;
            }
            else
            break;
        }


        if(i>=j)
        return true;
        
        temp1 = b.substr(i , j-i+1);
        temp2 = a.substr(i , j-i+1);
        
        if(isPalindrome(temp1) || isPalindrome(temp2))
            return true;

        return false;
        
    }
};