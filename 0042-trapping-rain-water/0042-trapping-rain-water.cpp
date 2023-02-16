class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        vector<int> rMax(n);
        
        int maxi = 0;
        for(int i=n-1;i>=0;i--)
        {
            maxi = max(maxi , height[i]);
            rMax[i] = maxi;
        }
        
        int res = 0 , lMax = 0;
        for(int i=0;i<n;i++)
        {
            lMax = max(lMax , height[i]);
            
            int total = min(rMax[i] , lMax);
            res += (total-height[i]);
        }
      
        
        return res;
        
    }
};