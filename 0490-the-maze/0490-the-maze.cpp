class Solution {
public:
    int n, m;
    
    bool isValid(int r , int c)
    {
        return (r>=0 && c>=0 && r<n && c<m);
    }
   
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& dest) {
        
        n = maze.size() , m = maze[0].size();
        
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        
        queue<pair<int,int>> q;
        q.push({start[0] , start[1]});
        
        vector<vector<bool>> vis(n , vector<bool>(m,false));
        vis[start[0]][start[1]] = true;
        
        
        while(q.size())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            if(r==dest[0] && c==dest[1])
                return true;
            
            for(int ind=0;ind<4;ind++)
            {
                int newR = r+dx[ind];
                int newC = c+dy[ind];
                
                while(isValid(newR , newC) && maze[newR][newC] == 0)
                {
                    newR += dx[ind];
                    newC += dy[ind];
                }
                
                newR -= dx[ind];
                newC -= dy[ind];
                
                if(!vis[newR][newC])
                {
                    q.push({newR , newC});
                    vis[newR][newC] = true;
                }
                
                
            }
        }
        
        return false;
        
    }
};