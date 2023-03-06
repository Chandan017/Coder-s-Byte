class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int start = 0;
        
        for(auto it:arr)
        {
            int diff = it-start-1;
            
            if(diff >= k)
            {
                return (start+k);
            }
            start = it;
            k -= diff;
        }
        
        return start+k;
        
    }
};