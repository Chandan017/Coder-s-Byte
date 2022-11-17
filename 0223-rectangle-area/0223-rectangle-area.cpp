class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        
        long area1 = (ax2-ax1)*(ay2-ay1);
        long area2 = (bx2-bx1) * (by2-by1);
        
        long commonArea = 0;
        
        int leftX = max(ax1  , bx1);
        int rightX = min(ax2 , bx2);
        
        int xOverlap = rightX - leftX;
        
        int leftY = max(ay1 , by1);
        int rightY = min(ay2 , by2);
        
        int yOverlap = rightY - leftY;
        
        if(xOverlap > 0 && yOverlap > 0)
        {
            commonArea = xOverlap * yOverlap;
        }
        
        
        // cout<<commonArea<<" "<<xOverlap<<" "<<yOverlap<<endl;
        
        long totalArea = area1 + area2 - commonArea;
        
        
        return totalArea;
        
    }
};