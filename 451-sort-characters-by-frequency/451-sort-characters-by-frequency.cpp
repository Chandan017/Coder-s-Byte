class Solution {
public:
    string frequencySort(string s) {
        
        int freq[256]={0};
        string ans="";
        for(auto it:s)
            freq[it]++;
        
        priority_queue<pair<int , char> > pq;  
        
        for(int i=0;i<256;i++)
        {
            if(freq[i] > 0)
                pq.push({freq[i] , i});
        }
        
        while(pq.size())
        {
            int times = pq.top().first ;
            char c=pq.top().second;
            
            while(times--)
                ans += c;
            
            pq.pop();
        }
        
        return ans;
    }
};