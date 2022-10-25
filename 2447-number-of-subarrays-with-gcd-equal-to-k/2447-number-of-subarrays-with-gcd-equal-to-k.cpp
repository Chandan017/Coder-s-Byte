class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        
        int n = nums.size() , cnt = 0;
        
        for(int i=0;i<n;i++)
        {
            int prevGCD = nums[i];
            for(int j=i;j<n;j++)
            {
                int currGCD = gcd(prevGCD , nums[j]);
                if(currGCD == k)
                    cnt++;
                
                prevGCD = currGCD;
            }
            
            
        }
        return cnt;
        
    }
};