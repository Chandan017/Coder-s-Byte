class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        set<string> vis;
        int totalCombinations = pow(2,k);
        
        string window = "";
        
        for(auto it:s)
        {
            if(window.size() < k -1)
                window += it;
            else
            {
                window += it;
                
                vis.insert(window);
                
                window.erase(window.begin());
            }
        }
        
        if(vis.size()==totalCombinations)
            return true;
        else
            return false;
            
        
    }
};