class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        
        int n = grid.size() , m = grid[0].size();
        
        for(int i=0;i<n;i++)
        {
            sort(grid[i].begin() , grid[i].end());
        }
        
        int total =0;
        
        while(m--)
        {
            int maxi = 0;
            for(int i=0;i<n;i++)
            {
                maxi = max(maxi , grid[i].back());
                grid[i].pop_back();
            }
            
            total += maxi;
        }
        
        
        return total;
        
    }
};