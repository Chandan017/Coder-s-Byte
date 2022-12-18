/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    
    bool isCeleb(int i , int n)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
                continue;
            
            if(knows(i , j) || !knows(j,i))
                return false;
        }
        
        return true;
    }
    int findCelebrity(int n) {
        
        for(int i=0;i<n;i++)
        {
            if(isCeleb(i , n))
                return i;
        }
        return -1;
        
    }
};