class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        int n=nums.size();
        
        if(n==1)
            return 0;
        
        int ans1=0,ans2=0;
        int mid1=nums[(n-1)/2];
        int mid2=nums[(n+1)/2];
        
        for(int ele:nums){
            ans1+=abs(ele-mid1);
            ans2+=abs(ele-mid2);
        }   
        
        if(n%2==0)
        {
            int ans = min(ans1, ans2);
            return ans;
        }
        
        return ans1;
    
        
    }
};