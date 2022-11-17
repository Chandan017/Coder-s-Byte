class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        
        
        int leftX = max(rec1[0] , rec2[0]);
        int rightX = min(rec1[2] , rec2[2]);
        int xOverlap = rightX - leftX;
        
        int leftY = max(rec1[1] , rec2[1]);
        int rightY = min(rec1[3] , rec2[3]);
        int yOverlap = rightY - leftY;
        
        if(xOverlap > 0 && yOverlap > 0)
            return true;
        
        return false;
        
    }
};