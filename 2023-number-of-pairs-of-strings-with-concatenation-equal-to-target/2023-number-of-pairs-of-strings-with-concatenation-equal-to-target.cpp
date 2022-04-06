class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        
        int totalCnt =0;
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                string temp=nums[i];
                temp += nums[j];
                if(temp == target && i!=j)
                    totalCnt++;
            }
        }
        
        return totalCnt;
        
    }
};