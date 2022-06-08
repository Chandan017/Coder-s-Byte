class Solution {
public:
    vector<string> printVertically(string s) {
        
        int maxLen = 0;
        int currLen = 0;
        
        s += ' ';
        
        for(auto &it:s)
        {
            if(it==' ')
            {
                maxLen = max(maxLen , currLen);
                currLen = 0;
            }
            else
                currLen += 1;
        }
        
        vector<string> dict;
        string temp = "";
        for(auto &it:s)
        {
            if(it==' ')
            {
                while(temp.size() != maxLen)
                {
                    temp += ' ';
                }
                
                dict.push_back(temp);
                temp = "";
            }
            else
                temp += it;
        }
        
        int ind = 0;
        
        vector<string> ans;
        
        while(ind < maxLen)
        {
            string temp = "";
            for(auto &it:dict)
            {
                temp += it[ind];
            }
            
            while(temp.back() == ' ')
                temp.pop_back();
            
            ans.push_back(temp);
            ind++;
        }
        
        return ans;
        
        
    }
};