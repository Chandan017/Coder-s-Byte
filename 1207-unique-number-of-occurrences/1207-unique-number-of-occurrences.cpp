class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        map<int,int> mpp;
        
        for(auto it:arr)
            mpp[it]++;
        
        int n = arr.size();
        vector<bool> check(n+1 , false);
        
        for(auto it:mpp)
        {
            if(check[it.second]==true)
                return false;
            else
                check[it.second] = true;
        }
        
        
        
        return true;
        
    }
};