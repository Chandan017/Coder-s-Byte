class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        
        int n = nums.size() , maxi = 0;
        vector<bool> vis(n , false);
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                int cnt = 1 , startInd = nums[nums[i]];
                
                while(startInd != nums[i])
                {
                    cnt++;
                    vis[startInd] = true;
                    startInd = nums[startInd];

                }
                
                maxi = max(maxi , cnt);
            }
        }
        
        return maxi;
        
    }
};