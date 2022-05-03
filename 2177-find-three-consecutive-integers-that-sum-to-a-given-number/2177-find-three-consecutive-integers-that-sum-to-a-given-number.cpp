class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        
        long long x = num/3;
        
        vector<long long> ans;
        
        if(x + (x-1) + (x+1) == num)
        {
            ans.push_back(x-1);
            ans.push_back(x);
            ans.push_back(x+1);
            
        }
        
        return ans;
        
    }
};