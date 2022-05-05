class Solution {
public:
    int n, m;
    
    bool check(vector<vector<char>> &board , int r , int c , string &word , int currInd)
    {
        if(currInd == word.size())
            return true;
        
        if(r<0 || c<0 || r>=n || c>=m || board[r][c] != word[currInd])
            return false;
        
        char val = board[r][c];
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        
        board[r][c] = '*';
        
        for(int ind=0;ind<4;ind++)
        {
            int newR = r+dx[ind];
            int newC = c+dy[ind];
            
            if(check(board , newR , newC , word , currInd+1))
                return true;
        }
        
        board[r][c] = val;
        
        return false;
    }

    
    bool exist(vector<vector<char>>& board, string word) {
        
        n = board.size();
        m = board[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(check(board , i , j , word , 0))
                    return true;
            }
        }
        
        return false;
        
    }
};