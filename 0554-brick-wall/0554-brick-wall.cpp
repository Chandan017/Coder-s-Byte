class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        
        int n = wall.size();
        
    
        unordered_map<int,int> mpp;
        int sum = accumulate(wall[0].begin() , wall[0].end() , 0);
        
                
        for(int i=0;i<n;i++)
        {
            int prev = 0;
            for(int j=0;j<wall[i].size();j++)
            {
                prev += wall[i][j];
                
                if(prev < sum)
                    mpp[prev]++;
            }
        }
        
        int maxCnt = 0;
        
        for(auto it:mpp)
        {
            maxCnt = max(maxCnt , it.second);
        }

  
        return n-maxCnt;
        
    }
};