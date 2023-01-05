class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin() , points.end());
        int n = points.size();
        int totalArrows = 1 , firstEnd = points[0][1];
        
        for(int i=0;i<n;i++)
        {
            if(firstEnd < points[i][0])
            {
                totalArrows++;
                firstEnd = points[i][1];
            }
            
            firstEnd = min(points[i][1],firstEnd);
        }
        
        
        
        return totalArrows;
        
    }
};