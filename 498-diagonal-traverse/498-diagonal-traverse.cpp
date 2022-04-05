class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vec(n+m , vector<int> ());
        vector<int> ans;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                vec[i+j].push_back(mat[i][j]);
            }
        }
        
        for(int i=0;i<n+m;i++)
        {
            if(i%2==0)
            {
                reverse(vec[i].begin() , vec[i].end());
                
            }
            
            for(auto it:vec[i])
                ans.push_back(it);
        }
        
        return ans;
    }
};