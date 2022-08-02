class Solution {
public:
    
    int n , m;
    
    void helper(vector<vector<int>> &grid , int r , int c , int oldColor , int newColor)
    {
        if(r<0 || c<0 || r>=n || c>=m || grid[r][c] != oldColor)
            return ;
        
        grid[r][c] = newColor;
        
        helper(grid , r+1 , c , oldColor , newColor);
        helper(grid , r-1 , c , oldColor , newColor);
        helper(grid , r , c+1 , oldColor , newColor);
        helper(grid ,r , c-1 , oldColor , newColor);
        
        return ;
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        n = image.size() , m = image[0].size();
        
        int oldColor = image[sr][sc];
        
        if(oldColor != color)
            helper(image , sr , sc, oldColor , color);
        
        return image;
        
        
    }
};