class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        priority_queue<pair<int,pair<int,int>>> pq;
        vector<vector<int>> ans;
        
        for(auto num1 :nums1)
        {
            for(auto num2:nums2)
            {
                int sum = num1 + num2;
                
                if(pq.size() < k)
                    pq.push({sum , {num1 , num2}});
                else if(sum < pq.top().first)
                {
                    pq.pop();
                    pq.push({sum , {num1 , num2}});
                }
                else
                    break;
            }
        }
        
        while(pq.size())
        {
            ans.push_back({pq.top().second.first , pq.top().second.second});
            pq.pop();
        }
        
        return ans;
        
    }
};