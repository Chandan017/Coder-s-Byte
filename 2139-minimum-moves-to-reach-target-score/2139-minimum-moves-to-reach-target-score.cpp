class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        
        
        int cnt = 0;
        
        while(target != 1)
        {
            if(target%2==0 && maxDoubles)
            {
                target/=2;
                maxDoubles--;
            }
            else if(maxDoubles==0)
            {
                cnt += (target-1);
                break;
            }
            else
                target-=1;
            
            cnt++;
            
        }
        
        
        return cnt;
        
    }
};