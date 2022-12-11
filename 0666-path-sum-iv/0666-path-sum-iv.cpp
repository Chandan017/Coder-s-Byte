class Solution {
public:
    int pathSum(vector<int>& nums) {
        
        unordered_map<int,unordered_map<int,int>> mpp;
        
        for(auto &it:nums)
        {
            string curr = to_string(it);
            
            mpp[curr[0]-'0'][curr[1]-'0'] = curr[2]-'0';
        }
        
        queue<pair<int,int>> q;
        q.push({nums[0]%10 , 1});
        
        int currLevel = 1 , total = 0; 
        while(q.size())
        {
            int len = q.size();
            // int pos = 0;
            while(len--)
            {
                int curr = q.front().first;
                int pos = q.front().second;
                q.pop();
                
                if(mpp.find(currLevel+1) != mpp.end())
                {
                    unordered_map<int,int> it = mpp[currLevel+1];
                    bool flag = true;
                    
                    if(it.find((2*pos)-1) != it.end())
                    {
                        q.push({curr + it[(2*pos)-1] , (2*pos) - 1});
                        flag = false;
                    }
                    if(it.find((2*pos)) != it.end())
                    {
                        q.push({curr + it[(2*pos)] , (2*pos)});
                        flag = false;
                    }
                    
                    if(flag)
                        total += curr;
                }
                else
                {
                    total += curr;
                }
            }
            
            currLevel++;
        }
        
        
        return total;
    }
};