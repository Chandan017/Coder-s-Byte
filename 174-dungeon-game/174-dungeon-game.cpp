class Solution {
public:
    int n , m;
    
    
    int get(vector<vector<int>> &dungeon , int currX , int currY , vector<vector<int>> &dp)
    {
        if(currX >=n || currY>=m)
            return 1e4-1;
        
        if(dp[currX][currY] != -1)
            return dp[currX][currY];
        
        if(currX == n-1 && currY == m-1)
        {
            if(dungeon[currX][currY] <=0)
                return abs(dungeon[currX][currY]) + 1;
            return 1;
        }
        
        int right = get(dungeon , currX , currY+1 , dp);
        int down = get(dungeon , currX+1 , currY , dp);
        
        int ans = min(right , down ) - dungeon[currX][currY];
        
        if(ans <=0)
            ans = 1;
        
        return dp[currX][currY] = ans;
            
        
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        n = dungeon.size() , m=dungeon[0].size();
        vector<vector<int>> dp(n , vector<int>(m , -1));
        int ans = get(dungeon , 0 ,0 , dp);
        
        return ans;
        
    }
};