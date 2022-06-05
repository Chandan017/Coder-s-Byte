class NumMatrix {
public:
    
    vector<vector<int>> grid;
    
    NumMatrix(vector<vector<int>>& matrix) {
        
        int n = matrix.size() , m = matrix[0].size();
        for(int i=0;i<n;i++)
        {
            vector<int> eachRow(m);
            int sum = 0;
            
            for(int j=0;j<m;j++)
            {
                sum += matrix[i][j];
                eachRow[j] = sum;
            }
            
            grid.push_back(eachRow);
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int sum = 0;
        
        for(int r=row1;r<=row2;r++)
        {
            int currLevelSum = grid[r][col2];
            if(col1 != 0)
                currLevelSum -= grid[r][col1-1];
            
            sum += currLevelSum;
        }
        
        
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */