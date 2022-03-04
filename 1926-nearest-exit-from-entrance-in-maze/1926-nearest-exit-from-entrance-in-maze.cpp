class Solution {
public:
    int n,m;
    
    bool isExit(int x,int y)
    {
        if(x==0 || y==0 || x==n-1 || y==m-1)
            return true;
        return false;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        n=maze.size();
        m=maze[0].size();
        
        queue<pair<int,pair<int,int>>> q;
        int r=entrance[0] , c=entrance[1];
        q.push({0,{r,c}});
        
        maze[r][c]='+';
        
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        while(!q.empty())
        {
            int dist=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            
            cout<<x<<" "<<y<<" "<<dist<<endl;
            
            q.pop();
            
            if(isExit(x,y)==true && dist!=0)
                return dist;
            
            for(int ind=0;ind<4;ind++)
            {
                int newX=x+dx[ind];
                int newY=y+dy[ind];
                
                if(newX>=0 && newY>=0 && newX<n && newY<m && maze[newX][newY]=='.')
                {
                    q.push({dist+1 , {newX , newY}});
                    maze[newX][newY]='+';
                }
            }
        }
      
        
        return -1;
        
        
        
    }
};