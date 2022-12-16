class Solution {
public:
    int minimumKeypresses(string s) {
        
        vector<int> freq(26 , 0);
        int cnt = 1 , total = 0;
        for(auto it:s)
        {
            freq[it-'a']++;
        }
        
        sort(freq.begin() , freq.end() , greater<int>());
        
        for(auto it:freq)
        {
            if(cnt <= 9)
            {
                total += it;
            }
            else if(cnt <= 18)
            {
                total += (2*it);
            }
            else
            {
                total += (it*3);
            }
            cnt++;
        }
        
        return total;
    }
};