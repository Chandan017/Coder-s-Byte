class Solution {
    
    bool valid(char ch){
        if( (ch>='a' && ch<='z') || (ch>='A' && ch <= 'Z') || (ch>='0' && ch<='9'))
            return 1;
        
        else return 0;
    }
    
    char toLowerCase(char a){
        if ( (a>='a' && a<='z') || (a>='0' && a<='9'))
            return a;
        else return a-'A'+'a';
    }
    
    bool checkPalinedrome(string s){
        int i=0,j=s.length()-1;
        while (i<j){
            if (s[i] != s[j])
                return 0;
            i++;
            j--;
        }
        return 1;
    }
    
public:
    bool isPalindrome(string s) {
        int n=s.size();
       string temp="";
        for(int i=0;i<n;i++)
            if(valid(s[i]))
               temp.push_back(s[i]);
        
      
       
        for(int i=0;i<temp.size();i++)
          temp[i]=toLowerCase(temp[i]);
        cout<<temp;
        
       return checkPalinedrome(temp);

    }
};