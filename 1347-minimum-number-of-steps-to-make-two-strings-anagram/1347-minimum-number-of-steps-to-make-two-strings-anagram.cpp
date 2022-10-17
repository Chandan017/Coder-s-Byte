class Solution {
public:
    int minSteps(string s, string t) {
        
        map<char,int> mpp1 , mpp2;
        
        for(auto c:s)
        {
            mpp1[c]++;
        }
        
//         for(auto it:mpp1)
//         {
//             cout<<it.first<<"->"<<it.second<<"  ";
//             // totalConversions += it.second;
//         }
        
        for(auto c:t)
        {
            if(mpp1.find(c) != mpp1.end() && mpp1[c] > 0)
            {
                mpp1[c]--;
            }
            
        }
        
        
        int totalConversions = 0;
        
        // cout<<endl;
        for(auto it:mpp1)
        {
            // cout<<it.first<<"->"<<it.second<<"  ";
            totalConversions += it.second;
        }
        
      
        
        return totalConversions;
        
    }
};