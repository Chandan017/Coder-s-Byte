class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        
        long long total = 0;
        int maxi = 0;
        
        for(auto it:damage)
        {
            total += it;
            maxi = max(maxi , it);
        } 
        
        
        total = total - min(maxi , armor) + 1;
        
        return total;
        
    }
};