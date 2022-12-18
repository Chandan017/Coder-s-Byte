class Solution {
public:
    bool isValid(int r , int c)
    {
        return (r>=0 && c>=0 && r<8 && c<8);
    }
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        
        set<vector<int>> queenLocations(queens.begin() , queens.end());
        
        int r = king[0] , c = king[1];
        vector<vector<int>> res;
        
        int dx[] = {-1,1,0,0 , -1 ,-1 ,1 , 1};
        int dy[] = {0,0,-1,1,-1 ,1 , 1 , -1};
        for(int ind=0;ind<8;ind++)
        {
            int newR = r , newC = c;
            bool flag = false;
            while(isValid(newR , newC))
            {
                if(queenLocations.find({newR , newC}) != queenLocations.end())
                {
                    flag = true;
                    break;
                }
                newR += dx[ind];
                newC += dy[ind];
            }
            
            if(flag)
                res.push_back({newR , newC});
        }
        
        return res;
        
    }
};