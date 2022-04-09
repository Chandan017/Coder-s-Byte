class Solution {
public:
    string frequencySort(string s) {
        
        int freq[256]={0};
        string ans="";
        for(auto it:s)
            freq[it]++;
                
        multimap<int , char , greater<int>> mpp;
        
        for(int i=0;i<256;i++)
        {
            if(freq[i] > 0)
                mpp.insert({freq[i] , i});
        }
        
        for(auto it:mpp)
        {
            int times = it.first ;
            char c=it.second;
            
            while(times--)
                ans += c;
            
        }
        
        return ans;
    }
};