class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int n = image.size();
        int m = image[0].size();
        
        int dx[]={-1,1,0,0};
        int dy[] = {0,0,-1,1};
        
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int oldColor = image[sr][sc];
        image[sr][sc] = newColor;
        
        if(newColor ==  oldColor)
            return image;
        
        while(q.size())
        {
            int x = q.front().first;
            int  y = q.front().second;
            q.pop();
            
            for(int  ind = 0;ind<4;ind++)
            {
                int  newR =  x + dx[ind];
                int newC = y +  dy[ind];
                
                if(newR>=0 && newC>=0  && newR<n  && newC<m && image[newR][newC]== oldColor)
                {
                    q.push({newR,newC});
                    image[newR][newC] = newColor;
                }
            }
        }
        
        return  image;

        
    }
};