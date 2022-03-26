class Solution {
public:
    int trap(vector<int>& height) {
        
        int n=height.size();
        vector<int> leftMax;
        vector<int> rightMax(n);
        
        int maxi=-1;
        for(int i=0;i<n;i++)
        {
            cout<<maxi<<" ";
            leftMax.push_back(maxi);
            maxi=max(maxi , height[i]);
        }
        cout<<endl;
        
        maxi=-1;
        
        for(int i=n-1;i>=0;i--)
        {
            rightMax[i]=maxi;
            maxi=max(maxi , height[i]);
        }
        for(auto it:rightMax)
            cout<<it<<" ";
        cout<<endl;
        
        vector<int> water;
        
        for(int i=0;i<n;i++)
        {
            int level=min(leftMax[i] , rightMax[i]);
            
            if(level<=height[i])
                water.push_back(0);
            else
                water.push_back(level- height[i]);
        }
        
        int trappedWater=0;
        
        for(auto it:water)
            trappedWater+=it;
        cout<<endl<<endl;
        return trappedWater;
        
    }
};