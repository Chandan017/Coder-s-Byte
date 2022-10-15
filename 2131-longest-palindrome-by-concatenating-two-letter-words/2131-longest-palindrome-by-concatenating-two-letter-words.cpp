class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        map<string,int> mpp;
        int totalLen = 0 ;
        bool flag = true;
        for(auto &it:words)
        {
            string original = it;
            reverse(it.begin() , it.end());
            
            if(mpp.find(it) != mpp.end() && mpp[it] > 0)
            {
                mpp[it]--;
                
                if(mpp[it] == 0)
                    mpp.erase(mpp.find(it));
                
                totalLen += 4;
            }
            else
                mpp[original]++;
        }
     
        for(auto it:mpp)
        {
            string original = it.first;
            reverse(original.begin() , original.end());
            
            if(original == it.first)
            {
                totalLen += 2;
                break;
            }
            
            
        }
        
      
        return totalLen;
        
    }
};