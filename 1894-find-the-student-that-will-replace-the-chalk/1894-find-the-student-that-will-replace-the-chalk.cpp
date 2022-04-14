class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        
        long long sum=0;int ans=0;
        for(auto i:chalk)
            sum+=i;
        
        int maxi=k%sum;
        int i=0;
        
        if(maxi == 0)
            return 0;
    
        while(i<chalk.size()){
            
            if(chalk[i] > maxi)
                return i;
            else
                maxi -= chalk[i];
            
            i++;
            
        }
    
        return 0;
    }
};