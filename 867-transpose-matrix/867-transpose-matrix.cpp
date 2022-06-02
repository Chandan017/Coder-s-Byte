class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        
        
        int n = matrix.size() , m = matrix[0].size();
        vector<vector<int>> ans(m);
        
        for(int col=0;col<m;col++)
        {
            for(int row=0;row<n;row++)
            {
                // row becomes col and col becomes row when we take transpose;
                ans[col].push_back(matrix[row][col]);
            }
        }
        
        return ans;
        
    }
};