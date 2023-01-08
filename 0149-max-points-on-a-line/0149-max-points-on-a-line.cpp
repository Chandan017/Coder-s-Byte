

class Solution {
public:
    int maxPoints(vector<vector<int>>& arr) {
        
        int n = arr.size() , maxi = INT_MIN;
        
        for(int i = 0; i < n; i++)
        {
            
            unordered_map<double, int> mp;
            
            int temp_max = 0;
            
            int x1 = arr[i][0];
            
            int y1 = arr[i][1];
            
            for(int j = 0; j < n; j++)
            {
                if(j == i)
                {
                    continue;
                }
                
                int x2 = arr[j][0];
                
                int y2 = arr[j][1];
                
                double nume = y2 - y1;
                
                double deno = x2 - x1;
                
                if(deno == 0)
                {
                    mp[INT_MAX]++;
                                        
                    temp_max = max(temp_max, mp[INT_MAX]);
                    
                    continue;
                }
                
                
                double slope = nume / deno;
                
                mp[slope]++;
                
                temp_max = max(temp_max, mp[slope]);
            }
            
            maxi = max(maxi, temp_max + 1);
        }
        
        return maxi;
    }
};