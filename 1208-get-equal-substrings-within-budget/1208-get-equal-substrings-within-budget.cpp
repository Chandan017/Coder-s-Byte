class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        
        int currCost = 0 , n = s.length() , prev = 0;
        int maxLen = 0 , i = 0;
        while(i<n)
        {
            currCost += abs(s[i]-t[i]);
            
            while(currCost > maxCost)
            {
                currCost -= abs(s[prev]-t[prev]);
                prev++;
            }
            // if(maxLen < (i-prev))
            //     cout<<prev<<"->"<<i<<"  ";
            maxLen = max(maxLen , (i-prev+1));
            i++;
        }
        // cout<<endl;
        
        return maxLen;
        
    }
};