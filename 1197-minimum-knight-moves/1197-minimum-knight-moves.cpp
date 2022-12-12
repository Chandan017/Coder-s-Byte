class Solution {
public:
    int minKnightMoves(int x, int y) {
        
        queue<pair<int,int>> q;
        q.push({0,0});
        int moves = 0;
        int dx[] = {-1 , -2 , -2 , -1 , 1 , 2 , 2 , 1};
        int dy[] = {-2 , -1 , 1 , 2 , 2 , 1 , -1 , -2};
        vector<vector<bool>> vis(1000 , vector<bool>(1000,false));
        // vis[300][300] = true;
        
        while(q.size())
        {
            int len = q.size();
            while(len--)
            {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                
                if(r==x && c==y)
                    return moves;
                
                for(int ind=0;ind<8;ind++)
                {
                    int newR = r + dx[ind];
                    int newC = c + dy[ind];
                    
                    if(vis[newR+302][newC+302] == false)
                    {
                        vis[newR+302][newC+302] = true;
                        q.push({newR , newC});
                    }
                }
            }
            
            moves++;
        }
        
        return moves;
        
    }
};