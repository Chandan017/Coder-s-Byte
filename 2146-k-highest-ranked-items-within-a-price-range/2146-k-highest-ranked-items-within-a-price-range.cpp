class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<int,int>> q;
        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>> > pq;
        q.push({start[0] , start[1]});
        
        int minPrice = pricing[0] , maxPrice = pricing[1];
        
        vector<vector<bool>> vis(n , vector<bool> (m,false));
        
        vis[start[0]][start[1]] = true;
        
        int distance = 0;
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        while(!q.empty())
        {
            int size = q.size();
            
            while(size--)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
               
                if(grid[x][y] >=minPrice && grid[x][y]<=maxPrice)
                {
                    pq.push({distance , grid[x][y] ,x ,y});
                    
                    
                }
    
                for(int ind=0;ind<4;ind++)
                {
                    int newX = x+dx[ind];
                    int newY = y+dy[ind];
                    
                    if(newX >=0 && newY>=0 && newY<m && newX<n && grid[newX][newY] !=0 && vis[newX][newY] ==false)
                    {
                        q.push({newX , newY});
                        vis[newX][newY] = true;
                    }
                    
                }
            }
            distance++;
            if(pq.size() == k)
                break;
        }
        
        vector<vector<int>> ans;
        while(pq.size() && ans.size() !=k)
        {
            auto it = pq.top();
            pq.pop();
            ans.push_back({it[2] , it[3] });
        }
        
       
        return ans;
        
    }
};