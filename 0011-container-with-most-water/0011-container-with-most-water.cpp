class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int maxi = 0 , l = 0 , r = height.size()-1;
        
        while(l<r)
        {
            int curr = min(height[l] , height[r]) * (r-l);
            maxi = max(maxi , curr);
            
            if(height[l] <= height[r])
                l++;
            else
                r--;
        }
        
        
        
        return maxi;
        
    }
};