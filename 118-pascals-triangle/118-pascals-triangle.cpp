class Solution {
public:
    
    int dp[31][31];
    
    int get(int r , int c)
    {
        if(r<0 || c<0 || c > r)
            return 0;
        
        if(r==0 && c==0)
            return 1;
        
        if(dp[r][c] )
            return dp[r][c];
        
        dp[r][c] = get(r-1 , c-1) + get(r-1 , c);
        
        return dp[r][c];
        
        
        
    }
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans;
        
        for(int i=0;i<numRows;i++)
        {
            vector<int> temp;
            
            for(int j=0;j<=i;j++)
            {
                int val = get(i , j);
                temp.push_back(val);
            }
            
            ans.push_back(temp);
        }
        
        return ans;
        
    }
};