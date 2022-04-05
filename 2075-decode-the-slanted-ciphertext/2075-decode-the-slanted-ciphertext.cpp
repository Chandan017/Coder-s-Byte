class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        
        int size=encodedText.length();
        int col=size/rows;
        string ans="";
        int c=0;
        int diff=col+1;
        while(c<col)
        {
            int ind=c;
            while(ind<size)
            {
                ans += encodedText[ind];
                ind+=diff;
            }
            c++;
        }
        
        while(ans.back()==' ')
            ans.pop_back();
        return ans;
        
    }
};