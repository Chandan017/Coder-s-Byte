class Solution {
public:
    
    int shortestPathLength(vector<vector<int>>& graph) {
        // to know number of nodes
        int n=graph.size(); 
        
         // if all nodes are visited then mask will be equal to allVis i.e, (11111) in case of 5 nodes
        int allVis=(1<<n)-1;
        int minLen=-1;
        
        
        // for storing node , currentDistance and which nodes are covered till now . Initially (00000) in case of 5 nodes
        queue<pair<int,pair<int,int>>> q; 
        
         // for not getting into a cycle 
        set<pair<int,int>> vis;
        
        
        // We can start from any node so we push every node into the queue
        // with a distance of 0 and mask 00000
        for(int i=0;i<n;i++)
        {
            int mask=(1<<i);
            q.push({i,{0,mask}});
            vis.insert({i,mask});
        }
        
        
        // normal BFS 
        // it will give shortest path to visit all nodes
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            
            int val=node.first , dist=node.second.first , mask=node.second.second ;
            
            // if all nodes are visited then mask would have to be equal to allVis
            // so we store it into our minLen variable and break beacuse we got our answer
            if(mask==allVis)
            {
                minLen=dist;
                break;
            }
            
            
            // if all nodes are not visited yet
            // then we will traverse on the connected nodes of that node
            for(auto connectedNode:graph[val])
            {
                
                // update our mask so that visited node change is reflected
                int newMask=(mask | (1<<connectedNode));
                
                
                // if that node is already in the queue with the same visited mask then we don't
                // need to add it into the queue
                if(vis.count({connectedNode, newMask}))
                    continue;
                
                // but if it is not visited yet then we will push it into the queue
                // and mark it as visited
                else
                {
                    q.push({connectedNode , {dist+1 , newMask}});
                    vis.insert({connectedNode , newMask});
                }
                
                
            }
        }
        
        // minLen stores the the minimum length to visit all nodes
        // so we simply return it
        
        
        return minLen;
        
    }
};