class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        
        vector<int> adj[n];
        for(int i=0;i<manager.size() ; i++)
        {
            if(manager[i]!=-1)
                adj[manager[i]].push_back(i);
        }
        
        int maxTime=0;
        queue<pair<int,int>> q;
        
        q.push({headID , 0});
        
        while(!q.empty())
        {
            int size=q.size();
            
            while(size--)
            {
                int currManager=q.front().first;
                int timeTaken=q.front().second;
                
                q.pop();
                
                int totalTime=timeTaken + informTime[currManager];
                
                maxTime=max(maxTime ,totalTime);
                
                for(auto &it:adj[currManager])
                    q.push({it,totalTime});
            }
        }
        
        return maxTime;
        
    }
};