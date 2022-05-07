class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> pq;
        vector<vector<int>> ans;
        int n1 = nums1.size() , n2 = nums2.size();
        pq.push({nums1[0] + nums2[0] , 0,0});
        set<pair<int,int>> vis;
        while(pq.size() && k--)
        {
            vector<int> temp = pq.top();
            pq.pop();
            
            ans.push_back({nums1[temp[1]] , nums2[temp[2]]});
            
            if(temp[1]+1 < n1 && vis.find({temp[1]+1 , temp[2]}) == vis.end())
            {
                 pq.push({nums1[temp[1]+1] + nums2[temp[2]] , temp[1]+1 , temp[2]});
                vis.insert({temp[1]+1 , temp[2]});
            }
               
            
            if(temp[2]+1 < n2 && vis.find({temp[1] , temp[2]+1}) == vis.end())
            {
                pq.push({nums1[temp[1]]+nums2[temp[2]+1] , temp[1] , temp[2]+1});
                vis.insert({temp[1] , temp[2]+1});
            }
                
        }
        
        return ans;
        
    }
};