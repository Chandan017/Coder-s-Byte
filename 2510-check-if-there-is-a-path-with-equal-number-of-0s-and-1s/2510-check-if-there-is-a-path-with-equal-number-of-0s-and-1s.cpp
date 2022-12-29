class Solution {
public:
    int n,m;
    bool dp[101][101][200] = {};
    bool check(vector<vector<int>> &grid , int r , int c , int target)
    {
        if(r>=n || c>=m || target<0 || dp[r][c][target])
            return false;
                
        dp[r][c][target] = true;
        
        target -= grid[r][c];
        

        if(r==n-1 && c==m-1)
        {
            if(target == 0)
                return true;
            
            return false;
        }
        
        return check(grid , r , c+1 , target) ||  check(grid , r+1 , c , target);
        
    }
    
    bool isThereAPath(vector<vector<int>>& grid) {
     
        n = grid.size() , m = grid[0].size();
        
        if((n+m-1) % 2 != 0)
            return false;
        
        bool res = check(grid , 0 , 0 , (n+m-1)/2);

        return res;
    }
};