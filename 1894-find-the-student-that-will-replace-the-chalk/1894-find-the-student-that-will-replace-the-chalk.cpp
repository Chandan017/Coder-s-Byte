class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        
        int n=chalk.size();
        long long perCycleUsage  = 0;
        
        for(int i=0;i<n;i++)
            perCycleUsage += chalk[i];
        
        if(k > perCycleUsage)
            k = k%perCycleUsage;
        
        if(k==0)
            return 0;
        
        for(int i=0;i<n;i++)
        {
            if(k < chalk[i])
                return i;
            else
                k -= chalk[i];
        }
        
        return 0;
       
    }
};