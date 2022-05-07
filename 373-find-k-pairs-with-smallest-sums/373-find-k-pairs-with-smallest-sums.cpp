class Solution {
public:
    
#define ppi pair<int,pair<int,int>> 
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        priority_queue<ppi , vector<ppi> , greater<ppi> > pq;
        vector<vector<int>> ans;
        int n1 = nums1.size() , n2 = nums2.size();
        
        
        pq.push({nums1[0] + nums2[0] , {0,0}});
        
        while(pq.size() && k--)
        {
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            
            ans.push_back({nums1[i] , nums2[j]});
            
            if(i+1 < n1 )
            {
                int sum = nums1[i+1] + nums2[j];
                pq.push({sum , {i+1 , j}});
            }
            
            if(i==0 && j+1 < n2)
            {
                int sum = nums1[i] + nums2[j+1];
                pq.push({sum , {i , j+1}});
            }
        }
        
        return ans;
        
    }
};