class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n=rooms.size();
        
        queue<int> q;
        q.push(0);
        vector<bool> vis(n,0);
        vis[0]=1;
        
        int totalOpened=0;
        while(!q.empty())
        {
            int r=q.front();
            q.pop();
            totalOpened++;
            
            for(auto &it:rooms[r])
            {
                if(!vis[it])
                {
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        
        if(totalOpened!=n)
            return false;
        
        return true;
        
    }
};