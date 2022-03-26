class Solution {
public:
    int trap(vector<int>& height) {
        
        int n=height.size();
        vector<int> leftMax;
        vector<int> rightMax(n);
        
        int maxiL=-1 , maxiR=-1;
        for(int i=0;i<n;i++)
        {
            leftMax.push_back(maxiL);
            maxiL=max(maxiL , height[i]);
            
            rightMax[n-i-1]=maxiR;
            maxiR=max(maxiR , height[n-i-1]);
        }
        
        int trappedWater=0;
        for(int i=0;i<n;i++)
        {
            int level=min(leftMax[i] , rightMax[i]);
            
            if(level > height[i])
                trappedWater += (level- height[i]);
        }
        return trappedWater;
        
    }
};