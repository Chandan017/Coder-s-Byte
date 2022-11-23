class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        
        unordered_set<string> st;
        
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j] != '.')
                {
                     string r = "r" + to_string(i) + board[i][j];
                     string c = "c" + to_string(j) + board[i][j];
                     string box = "b" + to_string((i/3)*3 + (j/3)) + board[i][j];
                    
                    if(st.find(r) == st.end() && st.find(c) == st.end() && st.find(box) == st.end())
                    {
                        st.insert(r);
                        st.insert(c);
                        st.insert(box);
                    }
                    else
                        return false;
                }
               
            }
        }
        
        
        return true;
        
    }
};