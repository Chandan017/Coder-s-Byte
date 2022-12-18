class Solution {
public:
    int maxCoins(vector<int>& piles) {
        
        sort(piles.begin() , piles.end() , greater<int>());
        int i=1 , j = piles.size()-1;;
        int total = 0;
        while(i<piles.size() && i<j)
        {
            total += piles[i];
            
            i += 2;
            j--;
        }
        
        return total;
    }
};