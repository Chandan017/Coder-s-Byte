class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int currEle = matrix[0][m-1];
        int r = 0 , c = m-1;
        
        while(r<n && c>=0)
        {
            currEle = matrix[r][c];
            
            if(currEle == target)
                return true;
            if(currEle > target)
                c--;
            else
                r++;
            
        }
        
        
        return false;
        
    }
};