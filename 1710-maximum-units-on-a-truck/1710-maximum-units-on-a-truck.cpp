class Solution {
public:
    
    static bool comp(vector<int> &a , vector<int> &b)
    {
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort(boxTypes.begin() , boxTypes.end() , comp);
        
        int totalUnits = 0;
        
        for(auto it:boxTypes)
        {
            int boxCnt = it[0];
            
            int canTake = min(boxCnt , truckSize);
            
            truckSize -= canTake;
            
            totalUnits += (canTake*it[1]);
        }
        
        
        return totalUnits;
        
    }
};