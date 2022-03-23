class Solution {
public:
    int dp[101][101];
    int findAll(int x,int y , int m , int n)
    {
        if(x>=m  || y>=n)
            return 0;
        
        if(x==m-1 && y==n-1)
            return 1;
        if(dp[x][y])
            return dp[x][y];
        int right=findAll(x,y+1,m,n);
        int down=findAll(x+1 , y , m ,n);
        
        return dp[x][y]= right+down;
    }
    int uniquePaths(int m, int n) {
        
        int x=0 , y=0;
        
        int totalPaths=findAll(x,y,m,n);
        return totalPaths;
        
    }
};