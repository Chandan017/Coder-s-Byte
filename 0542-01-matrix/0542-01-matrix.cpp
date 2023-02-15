class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n = mat.size() , m = mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> res(n,vector<int>(m,-1));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j] == 0)
                {
                    res[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        int steps = 1;
        
        while(q.size())
        {
            int len = q.size();
            while(len--)
            {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                
                for(int ind=0;ind<4;ind++)
                {
                    int newR = r+dx[ind];
                    int newC = c+dy[ind];
                    
                    if(newR>=0 && newC>=0 && newR<n && newC<m && res[newR][newC] == -1)
                    {
                        res[newR][newC] = steps;
                        q.push({newR , newC});
                    }
                }
            }
            steps++;
        }
        
        return res;
        
    }
};