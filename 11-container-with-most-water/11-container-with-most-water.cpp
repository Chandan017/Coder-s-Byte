class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int maxArea = INT_MIN ;
        int l = 0 , r = height.size()-1;
        
        while(l<r)
        {
            int width = r-l;
            int currArea = width * min(height[l] , height[r]);
            
            maxArea = max(maxArea , currArea);
            
            if(height[l] <=height[r])
                l++;
            else
                r--;
        }
        
        return maxArea;
        
    }
};