class NumMatrix {
public:
    vector<vector<long>> grid;
    NumMatrix(vector<vector<int>>& matrix) {
        
        for(auto &it:matrix)
        {
            vector<long> temp;
            long sum = 0;
            for(auto &j:it)
            {
                sum += j;
                temp.push_back(sum);
            }
            grid.push_back(temp);
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int row1End = row1 , col1End = col2;
        int row2Start = row2 , col2Start = col1;
        
        long long sum = 0;
        
       for(int row = row1;row<=row2;row++)
       {
           sum += grid[row][col2];
           if(col1 !=0)
               sum -= grid[row][col1-1];
       }
        
        
        
        return sum;
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */