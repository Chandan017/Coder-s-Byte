class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        vector<int> nsl , nsr(n);
        
        int maxi = height[0];
        for(int i=0;i<n;i++)
        {
            maxi = max(maxi , height[i]);
            nsl.push_back(maxi);
        }
        
        
        maxi = 0;
        for(int i=n-1;i>=0;i--)
        {
            maxi = max(maxi , height[i]);
            nsr[i] = maxi;
        }
        int res = 0;
        for(int i=0;i<n;i++)
        {
            int total = min(nsl[i] , nsr[i]);
            res += (total-height[i]);
            // cout<<total<<" ";
        }
        // cout<<endl;
        // for(auto it:nsl)
        //     cout<<it<<" ";
        
        return res;
        
    }
};