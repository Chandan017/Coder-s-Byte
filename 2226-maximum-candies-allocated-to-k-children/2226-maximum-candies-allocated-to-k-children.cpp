class Solution {
public:
    
//     bool check(vector<int> &nums , long long mid , int k)
//     {
//         long long cnt=0;
//         int n=nums.size();
//         for(int i=0;i<n;i++)
//         {
//             int times = nums[i]/mid;
//             cnt += times;
            
//             if(cnt >=k)
//                 return true;
//         }
//         return false;
//     }
    bool check(vector<int>& nums, long long mid, long long k){
        int n = nums.size();
        long long cnt = 0;
        for(int i=0;i<n;i++){
            long long p = nums[i]/mid;
            cnt += p;
            if(cnt>=k) return true;
        }
        return false;
    }
   
    int maximumCandies(vector<int>& candies, long long k) {
        
        int high = 0;
        long long sum=0;
        for(auto it:candies)
        {
            sum+=it;
            high=max(it , high);
        }
        
        long long low=1;
       
        int ans=0;      
        while(low <= high)
        {
            long long mid = (low + high) / 2;
            bool flag = check(candies , mid , k);
            if(flag==true)
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