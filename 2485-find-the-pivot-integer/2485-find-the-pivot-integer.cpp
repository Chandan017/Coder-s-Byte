class Solution {
public:
    int pivotInteger(int n) {
        
        int sum = (n*(n+1)) / 2;
        
        int l = 0 , h = n;
        
        while(l<=h)
        {
            int mid = (l+h)/2;
            int curr =(mid*(mid+1))/2;

            if(curr == (sum - curr + mid))
                return mid;
            else if(curr < (sum - curr + mid))
                l = mid+1;
            else
                h = mid-1;
            
        }
        
        return -1;
    }
};