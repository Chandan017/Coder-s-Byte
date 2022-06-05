class NumMatrix {
public:
    
    vector<vector<int>> grid;
    
    NumMatrix(vector<vector<int>>& matrix) {
        
        for(auto &it:matrix)
        {
            vector<int> eachRow;
            int sum = 0;
            
            for(auto &j:it)
            {
                sum += j;
                eachRow.push_back(sum);
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