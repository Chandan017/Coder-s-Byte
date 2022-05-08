class Solution {
public:
    string reorganizeString(string s) {
        
        
        int freq[26]={0};
        
        for(auto &it:s)
            freq[it-'a']++;
        
        int n = s.length();
        priority_queue<pair<int,char>> pq;
        
        for(int i=0;i<26;i++)
        {
            if(freq[i]!=0)
            {
                if(freq[i] > (n+1)/2)
                    return "";
                pq.push({freq[i] , i+'a'});
            }
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
    
       
        
        return ans;
        
        
    }
};