class Solution {
public:
    
    int solve(vector<string> &arr , string str , int ind)
    {
        unordered_set<char> st(str.begin() , str.end());
        
        if(str.length() != st.size())
            return 0;
        
        int maxLen = str.length();
        
        for(int i=ind;i<arr.size();i++)
        {
            int currLen = solve(arr , str+arr[i] , i+1);
            
            maxLen = max(maxLen , currLen);
        }
        
        return maxLen;
    }
    
    int maxLength(vector<string>& arr) {
        
        string str = "";
        int res = solve(arr , str , 0);
        
        return res;
    }
};