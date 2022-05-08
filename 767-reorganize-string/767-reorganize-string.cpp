class Solution {
public:
    string reorganizeString(string s) {
        
        map<char , int> mpp;
        
        for(auto it:s)
            mpp[it]++;
        
        priority_queue<pair<int,char>> pq;
        
        for(auto it:mpp)
        {
            pq.push({it.second , it.first});
        }
        
        string ans="";
        
        
        while(pq.size())
        {
            auto it = pq.top();
            pq.pop();
            
            ans += it.second;
            
            if(pq.size())
            {
                auto j = pq.top();
                pq.pop();
                ans += j.second;
                
                if(j.first > 1)
                    pq.push({j.first -1 , j.second});
            }
            
            if(it.first > 1)
                pq.push({it.first - 1 , it.second});
        }
    
        
        for(int i=1;i<ans.length();i++)
        {
            if(ans[i] == ans[i-1])
                return "";
        }
        
        return ans;
        
        
    }
};