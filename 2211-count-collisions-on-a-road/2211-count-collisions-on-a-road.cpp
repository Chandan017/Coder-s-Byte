class Solution {
public:
    int countCollisions(string directions) {
        
        int n=directions.length();
        int fromRight=0;
        int cnt=0;
        
        int i=0;
        while(i<n && directions[i]=='L')
            i++;
        
        for(;i<n;i++)
        {
            if(directions[i]=='R')
                fromRight++;
            else
            {
                if(directions[i]=='S')
                    cnt+=fromRight;
                else
                    cnt+=fromRight+1;
                
                fromRight=0;
            }
        }
        return cnt;
        
    }
};