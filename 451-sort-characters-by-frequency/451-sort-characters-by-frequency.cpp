class Solution {
public:
    string frequencySort(string s) {
        
        int freq[256]={0};
        string ans="";
        for(auto it:s)
            freq[it]++;
                
        map<int , vector<char> , greater<int>> mpp;
        
        for(int i=0;i<256;i++)
        {
            if(freq[i] > 0)
                mpp[freq[i]].push_back(i);
        }
        
        for(auto it:mpp)
        {
            int times = it.first ;
            vector<char> &temp = it.second;
            
            for(auto j:temp)
            {
                int t=times;
                while(t--)
                    ans += j;
            }
            
        }
        
        return ans;
    }
};