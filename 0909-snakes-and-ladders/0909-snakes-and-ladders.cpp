class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<vector<bool>> visited(n , vector<bool>(n,false));
        
        queue<int> q;
        q.push(1);
        visited[n-1][0]=true;
        int steps=0;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)  
            {
                int currpos = q.front();
                if(currpos==n*n)
                        return steps;
                q.pop(); 
                for(int i=1;i<=6;i++)     
                {
                    int nextpos=currpos+i;
                    if(nextpos>n*n)
                        break;
                    int r = n - (nextpos-1)/n -1;  
                    int c = (nextpos-1)%n;           
                    if(r%2 == n%2)     
                        c = n-c-1;
                    
                    if(!visited[r][c])
                    {
                        visited[r][c]=true;
                        if(board[r][c]!=-1)
                            q.push(board[r][c]);  
                        else
                            q.push(nextpos);
                    }
                }
            }
            steps++;
        }
        
        return -1;        
    }
};