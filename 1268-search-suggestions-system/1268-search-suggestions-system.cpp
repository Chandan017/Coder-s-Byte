class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        map<string,set<string>> mpp;
        
        int n = products.size();
        
        for(int i=0;i<n;i++)
        {
            string word = products[i];
            string temp = "";
            int len = word.length();
            
            for(int j=0;j<len;j++)
            {
                temp += word[j];
                mpp[temp].insert(word);
            }
        }
        
        vector<vector<string>> ans;
        
        int len = searchWord.length();
        string temp = "";
        for(int i=0;i<len;i++)
        {
            temp += searchWord[i];
            
            vector<string> query;
            if(mpp.find(temp) != mpp.end())
            {
                int cnt = 3;
                for(auto &it:mpp[temp])
                {
                    if(query.size()==3)
                        break;
                    query.push_back(it);
                }
            }
            
            ans.push_back(query);
            
        }
        
        return ans;
        
    }
};