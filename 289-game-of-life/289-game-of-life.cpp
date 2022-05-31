class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>> ans(n , vector<int>(m));
        
        int dx[8] = {-1,1,0,0,-1,-1,1,1};
        int dy[8] = {0,0,-1,1,-1,1,-1,1};
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int liveCnt = 0;
                
                for(int ind = 0;ind < 8;ind++)
                {
                    int newX = i + dx[ind];
                    int newY = j + dy[ind];
                    
                    if(newX>=0 && newY>=0 && newX<n && newY<m && board[newX][newY]==1)
                        liveCnt++;                        
                }
                
                if(board[i][j]==1)
                {
                    if(liveCnt == 2 || liveCnt ==3)
                        ans[i][j] = 1;
                    else
                        ans[i][j] = 0;
                }
                else
                {
                    if(liveCnt == 3)
                        ans[i][j] = 1;
                    else
                        ans[i][j] = 0;
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                board[i][j] = ans[i][j];
        }
        
        return ;
        
    }
};