class TicTacToe {
public:
    
    vector<vector<int>> board;
    int n;
    
    bool checkCol(int c , int player)
    {
        for(int i=0;i<n;i++)
        {
            if(board[i][c] != player)
                return false;
        }
        return true;
    }
    
    bool checkRow(int row , int player)
    {
        for(int j=0;j<n;j++)
        {
            if(board[row][j] != player)
                return false;
        }
        return true;
    }
    
    bool checkDiagonal(int player)
    {
        for(int i=0;i<n;i++)
        {
            if(board[i][i] != player)
                return false;
        }
        return true;
    }
    
    bool checkAntiDiag(int player)
    {
        for(int i=0;i<n;i++)
        {
            if(board[i][n-i-1] != player)
                return false;
        }
        
        return true;
    }
    TicTacToe(int n) {
        
        board.assign(n , vector<int>(n,0));
        this->n = n;
    }
    
    int move(int row, int col, int player) {
        
        board[row][col] = player;
        
        if(checkCol(col , player) || checkRow(row , player))
            return player;
        
        if(row==col && checkDiagonal(player))
            return player;
        
        if(row==n-col-1 && checkAntiDiag(player))
            return player;
        
        return 0;
        
        
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */