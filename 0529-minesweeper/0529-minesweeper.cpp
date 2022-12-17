class Solution {
public:
    int n , m;
    int dx[8] = {-1,1,0,0,-1,-1,1,1};
    int dy[8] = {0,0,-1,1,-1,1,1,-1};
    bool isValid(int r , int c)
    {
        return (r>=0 && c>=0 && r<n && c<m);
    }
    
    int getCnt(vector<vector<char>> &board , int r, int c)
    {
        int cnt = 0;
        for(int ind=0;ind<8;ind++)
        {
            int newR = r+dx[ind];
            int newC = c+dy[ind];
            
            if(isValid(newR , newC) && board[newR][newC] == 'M')
                cnt++;
        }
        
        return cnt;
    }
    
    void fill(vector<vector<char>> &board , int r ,int c)
    {

        int adjMines = getCnt(board , r , c);
        
        if(adjMines == 0)
        {
            board[r][c] = 'B';
            
            for(int ind=0;ind<8;ind++)
            {
                int newR = r+dx[ind];
                int newC = c+dy[ind];
                
                if(isValid(newR , newC) && board[newR][newC] == 'E')
                {
                    fill(board , newR , newC);
                }
            }
        }
        else
            board[r][c] = (adjMines+'0');
        
        return ;
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        
        n = board.size() , m = board[0].size();
        
        if(board[click[0]][click[1]] == 'M')
        {
            board[click[0]][click[1]] = 'X';
        }
        else
        {
           fill(board , click[0] , click[1]);
        }
        
        return board;
        
    }
};