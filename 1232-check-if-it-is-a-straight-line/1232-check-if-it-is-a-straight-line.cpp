class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        int n=coordinates.size();
        if(n==2)
            return true;
        
        int prevX=coordinates[0][0];
        int prevY=coordinates[0][1];
        
        int dx=coordinates[1][0] - prevX;
        int dy=coordinates[1][1] - prevY;
        
        for(int i=2;i<n;i++)
        {
            int x=coordinates[i][0];
            int y=coordinates[i][1];
            
            if(dy*(x-prevX) != dx*(y-prevY))
                return false;
            
            
        }
        
        return true;
        
    }
};