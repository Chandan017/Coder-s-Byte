class Solution {
public:
    static bool comp(vector<long long> &a , vector<long long> &b)
    {
        return (a[0] > b[0]);
    }
    
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int n = nums1.size();
        vector<vector<long long>> nums;
        
        for(int i=0;i<n;i++)
        {
            nums.push_back({nums2[i] , nums1[i]});
        }
        sort(nums.begin() , nums.end() , comp);
        long long res = 0 , sum = 0;
        
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        
        for(auto it:nums)
        {
            if(pq.size() == k)
            {
                sum -= pq.top();
                pq.pop();
            }
            
            sum += it[1];
            pq.push(it[1]);
            
            if(pq.size() == k)
            {
                long long curr = sum * it[0];
                
                res = max(res , curr);
            }
        }
        
        
        return res;       
    }
};