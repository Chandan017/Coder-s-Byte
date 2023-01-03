class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        
        int cnt = 0 , n = strs.size();
        
        for(int j=0;j<strs[0].length();j++)
        {
            for(int i=1;i<n;i++)
            {
                if(strs[i][j] < strs[i-1][j])
                {
                    cnt++;
                    break;
                }
            }
        }
        
        
        
        return cnt;
        
    }
};