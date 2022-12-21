class Solution {
public:
    int n,m;
    
    int getSum(vector<vector<int>> &grid , int r , int c)
    {
        int sum = grid[r][c] + grid[r-1][c] + grid[r-1][c-1] + grid[r-1][c+1] + grid[r+1][c] + grid[r+1][c-1] + grid[r+1][c+1];
        
        return sum;
    }
    int maxSum(vector<vector<int>>& grid) {
        
        n = grid.size() , m = grid[0].size();
        int maxSum = 0;
        for(int i=1;i<n-1;i++)
        {
            for(int j=1;j<m-1;j++)
            {
                int currSum = getSum(grid , i , j);
                maxSum = max(maxSum , currSum);
            }
        }
        
        return maxSum;
        
    }
};