class Solution {
public:
    int n,m;
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    
    void flipToA(int r , int c , vector<vector<char>> &board)
    {
        if(r<0 || c<0 || r==n || c==m || board[r][c] != 'O')
            return ;
        
        board[r][c] = 'A';
        for(int ind=0;ind<4;ind++)
        {
            int newR = r+dx[ind];
            int newC = c+dy[ind];
            
            flipToA(newR , newC , board);
        }
        return ;
    }
    
    void solve(vector<vector<char>>& board) {
        
        n = board.size() , m = board[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || j==0 || i==n-1 || j==m-1)
                {
                    
                    if(board[i][j] == 'O')
                    {
                        flipToA(i,j,board);
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
        }
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                if(board[i][j] == 'A')
                    board[i][j] = 'O';
        }
        
        return ;
    }
};