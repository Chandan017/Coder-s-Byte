class Solution {
public:
    bool same(unordered_map<char,int> &tMap , unordered_map<char,int> &sMap)
    {
        for(auto it:tMap)
        {
            if(sMap.find(it.first) != sMap.end()  && sMap[it.first] >= it.second)
                continue;
            else
                return false;
        }
        
        return true;
    }
   
    string minWindow(string s, string t) {
        
        
        if(s.length() < t.length())
            return "";
        
        unordered_map<char,int> tMap  , sMap;
        
        for(auto &it:t)
            tMap[it]++;
        
        string res = "" , curr = "";
        
        int n = s.length() , prevInd = 0;
        
        for(int i=0;i<n;i++)
        {
            curr += s[i];
            sMap[s[i]]++;
            
            if(same(tMap , sMap))
            {
                while(prevInd < i && sMap[s[prevInd]] > tMap[s[prevInd]])
                {
                    sMap[s[prevInd]]--;
                    
                    curr.erase(curr.begin());
                    prevInd++;
                }
                
                if((i-prevInd+1) < res.length() || res.length()==0)
                {
                    res = curr;
                }
                
                sMap[s[prevInd]]--;
               
                curr.erase(curr.begin());
                prevInd++;
            }
        }
        

        
        
   
        // cout<<endl<<endl;
        
        return res;
        
        
    }
};