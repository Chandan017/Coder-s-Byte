class Solution {
public:
    
    bool checkPalindrome(string &s , int i , int j)
    {
        
        while(i<j)
        {
            if(s[i] != s[j])
                return false;
            
            i++;
            j--;
        }
        
        return true;
    }
    bool validPalindrome(string s) {
        
        int low=0 , high=s.length()-1;
        
        while(low<high)
        {
            if(s[low] != s[high])
            {
                bool firstPart = checkPalindrome(s , low+1 , high);
                bool secondPart = checkPalindrome(s , low , high-1);
                
                return (firstPart || secondPart);
            }
            
            low++;
            high--;
        }
        
        return true;
        
    }
};