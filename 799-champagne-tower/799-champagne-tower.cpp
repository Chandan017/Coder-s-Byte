class Solution {
public:
    
    double dp[102][102];
    double get(int r , int c , double leftDrink)
    {
        if(r<0 || c<0 || c>r)
            return 0.00;
        
        if(r==0 && c==0)
        {
            return leftDrink;
        }
        
        if(dp[r][c]>-1)
            return dp[r][c];
        
        double firstPart=(get(r-1,c-1,leftDrink)-1)/2;
        
        if(firstPart<0.00)
        {
            firstPart=0.00;
        }
        
        double secondPart=(get(r-1,c,leftDrink)-1)/2;
        
        if(secondPart<0.00)
            secondPart=0.00;
        
        return  dp[r][c]=firstPart+secondPart;
        
       
        
            
    }
    double champagneTower(int poured, int row, int col) {
        
        memset(dp, -1, sizeof(dp));
        
        double ans=get(row,col,poured);
        if(ans >1.00000)
            ans=1.00000;
        
       
        return ans;
        
    }
};