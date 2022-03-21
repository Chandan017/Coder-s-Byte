class Solution {
public:
    
    int dp[35][35];
    int get(int r,int c)
    {
        if(r<0 || c<0 || c>r)
            return 0;
        
        if(r==0 && c==0)
            return 1;
        
        if(dp[r][c])
            return dp[r][c];
        return  dp[r][c]=get(r-1,c-1)+get(r-1,c);
    }
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        
        for(int i=0;i<rowIndex+1;i++)
        {
            int x=get(rowIndex,i);
            ans.push_back(x);
        }
        
        
        return ans;
    }
};