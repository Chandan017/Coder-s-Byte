class Solution {
public:
    int cnt = 0;
    
    bool isSafe(vector<string> &board , int row , int col , int n)
    {
        int dupRow = row;
        int dupCol = col;
        
        while(row>=0 && col>=0)
        {
            if(board[row][col] =='Q')
                return false;
            row--;
            col--;
        }
        
        row= dupRow , col = dupCol;
        
        while(col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            col--;
        }
        
        col = dupCol;
        
        while(row<n && col>=0)
        {
            if(board[row][col] == 'Q')
                return false;
            row++;
            col--;
        }
        
        return true;
    }
    
    void solve(vector<string> &board , int col , int n)
    {
        if(col==n)
        {
            cnt += 1;
            return ;
        }
        
        for(int row=0;row<n;row++)
        {
            if(isSafe(board , row , col ,n))
            {
                board[row][col] ='Q';
                solve(board , col+1 , n);
                board[row][col] = '.';
            }
        }
        
        return ;
    }
    
    int totalNQueens(int n) {
        
        string str(n,'.');
        vector<string> board(n,str);
        
        solve(board , 0 , n);
        
        return cnt;
        
    }
};