class Solution {
public:
    int countOdds(int low, int high) {
        
        int totalOdds = (high+1)/2;
        int prevOdds = (low+1)/2;
        
        if(low%2 == 1)
            prevOdds--;
        
        // cout<<totalOdds<<" "<<prevOdds<<endl;
        return (totalOdds - prevOdds);
        
        
    }
};