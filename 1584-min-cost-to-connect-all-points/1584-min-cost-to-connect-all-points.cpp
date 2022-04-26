class Solution {
public:
    
    int getParent(vector<int> &parent , int node)
    {
        if(parent[node]==node)
            return node;
        
        parent[node] = getParent(parent , parent[parent[node]]);
        
        return parent[node];
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        vector<int> parent(n);
        iota(parent.begin() , parent.end() , 0);
    
        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>> > pq;
        int edges = 0;
        int ans = 0;
        
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                
                pq.push({dist , i , j});
            }
        }
        
        while(edges != n-1)
        {
            vector<int> temp = pq.top();
            pq.pop();
            
            int p1 = getParent(parent , temp[1]);
            int p2 = getParent(parent , temp[2]);
            
            if(p1 != p2)
            {
                ans += temp[0];
                parent[p1] = p2;
                
                edges++;
            }
        }
        
        return ans;
    }
};