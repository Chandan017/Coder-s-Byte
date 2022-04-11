class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> ans(n,vector<int> (m,0));
         
        for(int i=0;i<n*m;i++)
        {
            int r=i/m;
            int c=i%m;
            
            int newIndex = (i+k) % (n*m);
            
            int newR = newIndex / m;
            int newC = newIndex % m;
            
            ans[newR][newC] = grid[r][c];
        }
        
        return ans;
        
    }
};