class Solution {
public:
    
    int n , m;
    
    bool checkRow(vector<vector<char>> &picture , int r)
    {
        int blackCnt = 0;
        for(int j=0;j<m;j++)
        {
            if(picture[r][j] == 'B')
                blackCnt++;
        }
        
        if(blackCnt == 1)
            return true;
        return false;
    }
    
    bool checkCol(vector<vector<char>> &picture , int c)
    {
        int blackCnt = 0;
        for(int i=0;i<n;i++)
        {
            if(picture[i][c] == 'B')
                blackCnt++;
        }
        
        if(blackCnt == 1)
            return true;
        return false;
    }
    int findLonelyPixel(vector<vector<char>>& picture) {
        
        n = picture.size() , m = picture[0].size();
        int cnt = 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(picture[i][j] == 'B')
                {
                    bool r = checkRow(picture , i);
                    bool c = checkCol(picture , j);
                    
                    if(r && c)
                        cnt++;
                }
            }
        }
        
        
        return cnt;
        
    }
};