class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        
        int mpp1[26]={0};
        int mpp2[26]={0};
        
        for(auto it:s)
            mpp1[it-'a']++;
        
        int cnt = INT_MAX;
        
        for(auto it:target)
        {
            mpp2[it-'a']++;
        }
        
        for(int i=0;i<26;i++)
        {
            if(mpp2[i]!=0)
            {
                int curr = mpp1[i] /mpp2[i];
                cnt = min(cnt , curr);
                
            }
        }
        
        
        return cnt;
        
    }
};