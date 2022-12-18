class Solution {
public:
    vector<int> parent;
    
    int findParent(int x)
    {
        if(parent[x] == x)
            return x;
        return findParent(parent[x]);
    }
    int earliestAcq(vector<vector<int>>& logs, int n) {
        
        parent.resize(n , 0);
        
        for(int i=0;i<n;i++)
            parent[i] = i;
        
        sort(logs.begin() , logs.end());
        for(auto it:logs)
        {
            int x = findParent(it[1]);
            int y = findParent(it[2]);
            
            if(x != y)
            {
                n--;
                
                if(n==1)
                    return it[0];
                parent[y] = x;
            }
        }
        
        return -1;
    }
};