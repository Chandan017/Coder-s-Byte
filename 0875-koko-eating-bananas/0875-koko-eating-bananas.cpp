class Solution {
public:
    bool isPossible(int k , vector<int> &piles , int h)
    {
        int curr = 0;
        
        for(auto it:piles)
        {
            curr += (it/k);
            
            if(it%k)
                curr++;
            
            if(curr > h)
                return false;
        }
        
        return curr<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        long low = 1 , high = 1e9;
        int res;
        while(low<=high)
        {
            long mid = (low+high)/2;
            
            if(isPossible(mid , piles , h))
            {
                res = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        
        return res;
        
    }
};