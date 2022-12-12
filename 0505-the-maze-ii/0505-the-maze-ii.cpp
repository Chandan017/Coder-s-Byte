class Solution {
public:
    int n,m;
    
    bool isValid(int r , int c)
    {
        return (r>=0 && c>=0 && r<n && c<m);
    }
    
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& dest) {
        
        n = maze.size() , m = maze[0].size();
        vector<vector<int>> dist(n , vector<int>(m,INT_MAX));
        
        dist[start[0]][start[1]] = 0;
        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> q;
        q.push({0 , start[0] , start[1]});
        
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        
        while(q.size())
        {
            int currDist = q.top()[0];
            int r = q.top()[1];
            int c = q.top()[2];
            q.pop();
            
            for(int ind=0;ind<4;ind++)
            {
                int newR = r + dx[ind];
                int newC = c + dy[ind];
                int cnt = 1;
                while(isValid(newR , newC) && maze[newR][newC] == 0)
                {
                    newR += dx[ind];
                    newC += dy[ind];
                    cnt++;
                }
                newR -= dx[ind];
                newC -= dy[ind];
                cnt--;
                
                if(dist[newR][newC] > currDist + cnt)
                {
                    dist[newR][newC] = currDist + cnt;
                    q.push({currDist+cnt , newR , newC});
                }
                // cout<<newR<<" "<<newC<<" "<<cnt<<endl;
            }
        }
        
        if(dist[dest[0]][dest[1]] == INT_MAX)
            return -1;
        
        return dist[dest[0]][dest[1]];
        
    }
};