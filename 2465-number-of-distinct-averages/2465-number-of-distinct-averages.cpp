class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        
        unordered_set<double> st;
        
        sort(nums.begin() , nums.end());
        
        int i = 0 , j = nums.size()-1;
        
        while(i<j)
        {
            double res = nums[i] + nums[j];
            
            res = res/2.0;
            i++;
            j--;
            
            st.insert(res);
        }
        
        
        
        
        return st.size();
    }
};