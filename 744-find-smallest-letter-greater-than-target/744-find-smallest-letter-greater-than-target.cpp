class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        char ans='1';
        
        int low = 0 , high = letters.size()-1;
        
        while(low <=high)
        {
            int mid = (low+high)/2;
            
            if(letters[mid] > target)
            {
                ans = letters[mid];
                high = mid-1;
            }
            else 
                low = mid+1;
        }
        
        
        if(ans=='1')
            ans = letters[0];
        
        return ans;
    }
};