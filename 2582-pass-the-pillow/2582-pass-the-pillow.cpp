class Solution {
public:
    int passThePillow(int n, int time) {
        
        int trip = time/(n-1);
        time %= (n-1);

        if(trip%2 == 0)
        {
            return time+1;
        }
        
        return (n-time);
        
    }
};