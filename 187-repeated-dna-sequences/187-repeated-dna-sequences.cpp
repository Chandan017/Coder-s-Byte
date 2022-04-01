class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        vector<string> ans;
        int n=s.length();
        
        if(n<10)
            return ans;
        
        string temp="";
        map<string , int> mpp;
        for(int i=0;i<n;i++)
        {
            if(i < 9)
            {
                temp+=s[i];
            }
            else
            {
                temp+=s[i];
                cout<<temp<<" ";
                
                mpp[temp]++;
                
                temp.erase(temp.begin());
            }
                
        }
        cout<<endl;
        for(auto it:mpp)
        {
            if(it.second > 1)
                ans.push_back(it.first);
        }
        
        return ans;
        
    }
};