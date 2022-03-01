class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int,int>> pq;
        
        for(int i=0;i<points.size();i++)
        {
            int x=points[i][0] , y=points[i][1];
            
            int dist=(x*x + y*y);
            
            pq.push({dist , i});
            
            if(pq.size() > k)
                pq.pop();
        }
        
        vector<vector<int>> ans;
        
        while(!pq.empty())
        {
            int ind=pq.top().second;
            pq.pop();

            
            ans.push_back(points[ind]);
        }
        
        return ans;
        
    }
};