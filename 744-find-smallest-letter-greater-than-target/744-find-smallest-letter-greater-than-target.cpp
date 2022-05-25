class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        char ans='1';
        
        for(auto it:letters)
        {
            if(it>target)
            {
                ans = it;
                break;
            }
        }
        
        if(ans=='1')
            ans = letters[0];
        
        return ans;
    }
};