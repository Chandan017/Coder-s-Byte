class Solution {
public:
    
    bool check(vector<int> &nums , int mid , long long k)
    {
        long long cnt=0;
        
        for(int i=0;i<nums.size();i++)
        {
            cnt += (nums[i] / mid);
            
            if(cnt >=k)
                return true;
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        
        int low=1 , high=*max_element(candies.begin() , candies.end());
        
        int ans=0;
        
        while(low <=high)
        {
            int mid=(low+high)/2;
            
            if(check(candies , mid , k))
            {
                ans=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        
        return ans;
        
    }
};