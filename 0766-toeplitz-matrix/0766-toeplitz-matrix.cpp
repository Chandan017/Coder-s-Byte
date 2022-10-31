class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        
        map<int,int> mpp;
        int n = matrix.size() , m = matrix[0].size();
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int diff = i-j;
                
                if(mpp.find(diff) != mpp.end() && mpp[diff] != matrix[i][j])
                    return false;
                mpp[diff] = matrix[i][j];
            }
        }
        
        
        return true;
        
    }
};