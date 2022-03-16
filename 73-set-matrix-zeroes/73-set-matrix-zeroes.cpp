class Solution {
public:
    
    int n,m;
    
    void fill(vector<vector<int>> &matrix,int r,int c)
    {
        for(int i=0;i<n;i++)
        {
            matrix[i][c]=0;
        }
        
        for(int j=0;j<m;j++)
        {
            matrix[r][j]=0;
        }
        
        return ;
    }
    void setZeroes(vector<vector<int>>& matrix) {
        
        n=matrix.size();
        m=matrix[0].size();
        vector<pair<int,int>> zero;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    zero.push_back({i,j});
                }
            }
        }
        
        for(auto &it:zero)
        {
            int r=it.first;
            int c=it.second;
            fill(matrix,r,c);
        }
        
    }
};