class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        
        
        long cnt=0;
        int n=arr.size();
        
        long freq[101]={0};
        
        for(auto it:arr)
            freq[it]++;
        
        vector<int> nums;
        
        for(int i=0;i<101;i++)
        {
            if(freq[i] > 0)
                nums.push_back(i);
        }
        
        for(int i=0;i<nums.size();i++)
        {
            int j=i , k =nums.size()-1;
            int newTarget = target - nums[i];
            
            while(j<=k)
            {
                if(nums[j] + nums[k]==newTarget)
                {
                    if(i< j && j<k)
                    {
                        cnt += (freq[nums[i]] * freq[nums[j]] * freq[nums[k]]);
                    }
                    else if(i==j && j<k)
                    {
                        cnt += freq[nums[i]] *  (freq[nums[i]] -1) /2 * freq[nums[k]];
                    }
                    else if(i<j && j==k)
                    {
                        cnt += freq[nums[i]] * freq[nums[j]] * (freq[nums[j]] -1) / 2;
                    }
                    
                    else if(i==j && j==k)
                    {
                        cnt += freq[nums[i]] * (freq[nums[i]]-1) * (freq[nums[i]] -2) /6 ;
                    }
                    
                    j++;
                    k--;
                }
                else if(nums[j] + nums[k] < newTarget)
                    j++;
                else
                    k--;
            }
        }
        
        
        int mod = 1e9 + 7;
        return cnt%mod;
    }
};