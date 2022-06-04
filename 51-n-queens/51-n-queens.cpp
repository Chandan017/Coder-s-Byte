class Solution {
public:
    
    bool isSafe(int row , int col , vector<string> &perLine , int n)
    {
        int dupRow = row;
        int dupCol = col;
        
        while(row >=0 && col>=0)
        {
            if(perLine[row][col]=='Q')
                return false;
            row--;
            col--;
        }
        
        row = dupRow;
        col = dupCol;
        
        while(col>=0)
        {
            if(perLine[row][col]=='Q')
                return false;
            col--;
        }
        
        col = dupCol;
        
        while(row<n && col>=0)
        {
            if(perLine[row][col]=='Q')
                return false;
            row++;
            col--;
        }
        
        return true;
    }
    
    void solve(vector<string> &perLine , vector<vector<string>> &board , int col, int n)
    {
        if(col==n)
        {
            board.push_back(perLine);
            return ;
        }
        
        for(int row = 0 ; row < n; row++)
        {
            if(isSafe(row , col , perLine, n))
            {
                perLine[row][col] = 'Q';
                solve(perLine , board , col+1 , n);
                perLine[row][col]='.';
            }
        }
        
        return ;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        string str(n,'.');
        vector<string> perLine(n,str);
        vector<vector<string>> chessBoard;
        
        solve(perLine , chessBoard , 0 , n);
        
        return chessBoard;
    }
};