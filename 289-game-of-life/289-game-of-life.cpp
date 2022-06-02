class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        int n=board.size();
        int m=board[0].size();
        
        vector<vector<int>> ans(n,vector<int>(m));
        
        int dx[8]={-1,1,0,0,-1,-1,1,1};
        int dy[8]={0,0,-1,1,-1,1,-1,1};
        
        for(int r=0;r<n;r++)
        {
            for(int c=0;c<m;c++)
            {
                int liveCnt = 0;
                
                for(int ind=0;ind<8;ind++)
                {
                    int newR = r + dx[ind];
                    int newC = c + dy[ind];
                    
                    if(newR>=0 && newC>=0 && newR<n && newC<m && board[newR][newC]==1)
                        liveCnt++;
                }
                
                if(board[r][c]==1)
                {
                    if(liveCnt==2 || liveCnt==3)
                        ans[r][c] = 1;
                    else
                        ans[r][c] = 0;
                }
                else
                {
                    if(liveCnt==3)
                        ans[r][c] = 1;
                    else
                        ans[r][c] = 0;
                }
            }
        }
        
        
        
        
        
        
        for(int r=0;r<n;r++)
        {
            for(int c=0;c<m;c++)
                board[r][c] = ans[r][c];
        }
        
        return ;
        
        
    }
};