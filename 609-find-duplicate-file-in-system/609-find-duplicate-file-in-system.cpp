class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        
        vector<vector<string>> res;
        map<string,vector<string>> mpp;
        
        for(auto dir:paths)
        {
            string currDir = "";
            int n = dir.length() , i = 0;
            while(i<n && dir[i] != ' ')
            {
                currDir += dir[i];
                i++;
            }
            i++;
            while(i<n)
            {
                string fileName = "" , fileData = "";
                    while(i<n && dir[i] != '(')
                {
                    fileName += dir[i];
                    i++;
                }
                i++;
                while(i<n && dir[i] != ')')
                {
                    fileData += dir[i];
                    i++;
                }
                
                i += 2;
                
                mpp[fileData].push_back(currDir + '/' +fileName);
                
            } 
            
        }
        
        for(auto it:mpp)
        {
            if(it.second.size() > 1)
                res.push_back(it.second);
        }
        
        
        return res;
        
    }
};