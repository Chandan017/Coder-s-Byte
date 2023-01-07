class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        
        bool bulky = false , heavy = false;
        
        long long volume = (long long)length * (long long)width * (long long) height;
        
        if(volume >= 1e9 || height >= 1e4 || width >= 1e4 || length >= 1e4)
            bulky = true;
        
        if(mass >= 100)
            heavy = true;
        
        if(bulky && heavy)
            return "Both";
        
        if(bulky && !heavy)
            return "Bulky";
        
        if(!bulky && heavy)
            return "Heavy";
        
        return "Neither";
        
    }
};