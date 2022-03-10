class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        unordered_map<string,int> mpp;
        
        int n=s.size();
        string temp="";
       vector<string> ans;
        for(int i=0;i<n;i++)
        {
            if(i<9)
            {
                temp+=s[i];
            }
            
            else
            {
                temp+=s[i];
                if(mpp.find(temp)!=mpp.end() && mpp[temp]==1)
                    ans.push_back(temp);
                
                mpp[temp]++;
                temp.erase(temp.begin());
            }
        }
      
        
        
        // for(auto &it:mpp)
        // {
        //     if(it.second>1)
        //         ans.push_back(it.first);
        // }
        
        return ans;
        
    }
};