class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        
        
        vector<int> curr;
        vector<string> res;
        int i = 1 , ind = 0;
        
        while(i<=n)
        {
            
            int cnt = 0;
            while(i < target[ind])
            {
                curr.push_back(i);
                res.push_back("Push");
                cnt++;
                i++;
            }
            
            while(cnt--)
            {
                res.push_back("Pop");
                curr.pop_back();
            }
            
            curr.push_back(i);
            res.push_back("Push");
            i++;
            ind++;
            
            if(curr == target)
                return res;
        }
        
        return res;
    }
};