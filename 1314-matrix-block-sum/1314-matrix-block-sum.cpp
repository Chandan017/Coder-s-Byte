class Solution {
public:
    int n, m;
    
    int getSum(vector<vector<int>> &mat , int r, int c , int k)
    {
       
        int i = r-k ;
        long sum = 0;
        int end = min(c+k , m-1) , start = max(c-k,0);
        
        while(i<=r+k)
        {
            if(i>=0 && i<n)
            {
                sum += mat[i][end];
                    
                if(start != 0)
                {
                    sum -= mat[i][start-1];
                }
                
            }
            i++;
        }
        
        return sum;
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        
        n = mat.size() , m = mat[0].size();
        vector<vector<int>> res(n , vector<int>(m));
        
        for(int i=0;i<n;i++)
        {
            int prev = 0;
            for(int j=0;j<m;j++)
            {
                prev += mat[i][j];
                
                mat[i][j] = prev;
            }
        }
    

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int currSum = getSum(mat , i , j , k);
                res[i][j] = currSum;
            }
        }
        
        
        
        
        return res;
        
    }
};