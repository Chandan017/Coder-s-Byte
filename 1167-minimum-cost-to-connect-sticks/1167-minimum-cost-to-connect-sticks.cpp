class Solution {
public:
    vector<int> parent;
    
    int getParent(int x)
    {
        if(parent[x] == x)
            return x;
        
        return getParent(parent[x]);
    }
    int connectSticks(vector<int>& sticks) {
        
        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> pq;
        int n = sticks.size();
        
        for(int i=0;i<n;i++)
        {
            pq.push({sticks[i] , i});
        }
        
        parent.resize(n);        
        for(int i=0;i<n;i++)
            parent[i] = i;
        
        int minCost = 0;
        
       while(pq.size())
       {
           auto x = pq.top();
           pq.pop();
           
           if(pq.size())
           {
               auto y = pq.top();
               pq.pop();
               
               if(getParent(x[1]) != getParent(y[1]))
               {
                   minCost += (x[0]+y[0]);
                   parent[x[1]] = y[1];
                   
                   pq.push({(x[0] + y[0]) , x[1]});
               }
           }
       }
        
        return minCost;
        
    }
};