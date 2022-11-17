class Solution {
public:
    string makeGood(string s) {

        string res = "";

        for(auto it:s)
        {
            if(res.length())
            {
                if(abs(res.back() - it) == 32)
                    res.pop_back();
                else
                    res += it;
            }
            else
                res += it;
        }

        return res;
        
    }
};