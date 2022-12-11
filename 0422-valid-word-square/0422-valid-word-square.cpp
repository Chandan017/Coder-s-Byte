class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        
        
        int n = words.size();
        
        for(int i=0;i<n;i++)
        {
            int m = words[i].length();
            for(int j=0;j<m;j++)
            {
                if(j>=n)
                    return false;
                if(words[i][j] != words[j][i])
                    return false;
            }
        }
        
        return true;
        
    }
};