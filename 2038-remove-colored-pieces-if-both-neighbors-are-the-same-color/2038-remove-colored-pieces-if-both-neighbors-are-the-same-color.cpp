class Solution {
public:
    bool winnerOfGame(string colors) {
        
        int n = colors.length() , alice = 0 , bob = 0;
        
        for(int i=1;i<n-1;i++)
        {
            if(colors[i-1] == 'A' && colors[i] == 'A' && colors[i+1] == 'A')
                alice++;
            else if(colors[i-1] == 'B' && colors[i] == 'B' && colors[i+1] == 'B')
                bob++;
        }
        
        
        if(alice > bob)
            return true;
        
        return false;
        
    }
};