class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        unordered_map<int,int> mpp;
        int res = 0 , n = fruits.size() , j = 0;
        
        for(int i=0;i<n;i++)
        {
            mpp[fruits[i]]++;
            
            while(mpp.size() > 2)
            {
                mpp[fruits[j]]--;
                if(mpp[fruits[j]] == 0)
                    mpp.erase(fruits[j]);
                j++;
            }
            
            if(mpp.size() <= 2)
            {
                int curr = 0;
                for(auto it:mpp)
                {
                    curr += it.second;
                }
                
                res = max(res , curr);
            }
        }
        
        return res;
    }
};