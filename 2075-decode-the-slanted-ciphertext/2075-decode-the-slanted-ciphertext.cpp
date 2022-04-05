class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        
        int size=encodedText.length();
        
        int col=size/rows;
        vector<vector<char>> text(rows , vector<char> (col));
        
        
        for(int i=0;i<size;i++)
        {
            text[i/col][i%col] = encodedText[i];
        }
        
        string ans="";
        int c=0;
        
        while(c<col)
        {
            int i=0  , j=c;
            while(i<rows && j<col)
            {
                ans +=text[i][j];
                i++;
                j++;
            }
            c++;
        }
        
        while(ans.back()==' ')
            ans.pop_back();
        return ans;
        
    }
};