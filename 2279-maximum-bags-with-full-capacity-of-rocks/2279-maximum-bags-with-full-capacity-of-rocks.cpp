class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        
        
        for(int i=0;i<rocks.size();i++)
        {
            capacity[i] -= rocks[i];
        }
        
        int cnt =0;
        sort(capacity.begin() , capacity.end());
        
        for(int i=0;i<capacity.size();i++)
        {
            if(capacity[i] <= additionalRocks)
            {
                additionalRocks -= capacity[i];
                cnt++;
            }
        }
        return cnt;
    }
};