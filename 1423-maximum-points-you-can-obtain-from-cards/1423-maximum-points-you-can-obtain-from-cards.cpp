class Solution {
public:
    
   
    int maxScore(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> prefix , suffix;
        int preSum = 0 , suffSum =0;
        
        prefix.push_back(0);
        suffix.push_back(0);
        
        for(int i=0;i<n;i++)
        {
            preSum += nums[i];
            suffSum += nums[n-1-i];
            
            prefix.push_back(preSum);
            suffix.push_back(suffSum);
        }
        
        int maxPoints = 0;
        
        int i=0,j=n;
        
        while(i<=n)
        {
            if(k-i<0)
                break;
            int firstPart = k-i;
            int secondPart = k-firstPart;
            int curr = prefix[firstPart];
            cout<<firstPart<<"->"<<prefix[firstPart]<<" "<<secondPart<<"->"<<suffix[secondPart]<<endl;
                        

            i++;
            if(secondPart >n)
                continue;
            
            curr += suffix[secondPart];
            
            maxPoints = max(maxPoints ,curr);
            
            
        }
        cout<<endl;
        
        return maxPoints;
        
    }
};