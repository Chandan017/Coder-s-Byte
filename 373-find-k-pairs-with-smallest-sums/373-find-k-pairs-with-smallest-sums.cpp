class Solution {
public:
    
#define ppi pair<int,pair<int,int>> 
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        priority_queue<ppi , vector<ppi> , greater<ppi> > pq;
        vector<vector<int>> ans;
        int n1 = nums1.size() , n2 = nums2.size();
        
        set<pair<int,int>> vis;
        
        pq.push({nums1[0] + nums2[0] , {0,0}});
        
        while(pq.size() && k--)
        {
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            
            ans.push_back({nums1[i] , nums2[j]});
            
            if(i+1 < n1 && vis.find({i+1 , j}) == vis.end())
            {
                int sum = nums1[i+1] + nums2[j];
                pq.push({sum , {i+1 , j}});
                vis.insert({i+1 , j});
            }
            
            if(j+1 < n2 && vis.find({i , j+1}) == vis.end())
            {
                int sum = nums1[i] + nums2[j+1];
                pq.push({sum , {i , j+1}});
                vis.insert({i ,j+1});
            }
        }
        
        return ans;
        
    }
};