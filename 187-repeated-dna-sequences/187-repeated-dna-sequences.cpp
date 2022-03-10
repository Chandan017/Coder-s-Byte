class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        map<string,int> mpp;
        
        int n=s.size();
        string temp="";
       
        for(int i=0;i<n;i++)
        {
            if(i<9)
            {
                temp+=s[i];
            }
            
            else
            {
                temp+=s[i];
                mpp[temp]++;
                temp.erase(temp.begin());
            }
        }
      
        vector<string> ans;
        
        for(auto &it:mpp)
        {
            if(it.second>1)
                ans.push_back(it.first);
        }
        
        return ans;
        
    }
};