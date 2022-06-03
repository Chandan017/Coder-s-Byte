class Solution {
public:
    
    vector<int> original;
    Solution(vector<int>& nums) {
        
        original = nums;
        
        
    }
    
    vector<int> reset() {
        
        return original;
        
    }
    
    vector<int> shuffle() {
        
        int n = original.size();
        vector<int> ans(original);
        
        for(int i=0;i<n;i++)
        {
            int random = rand()%(n);
            swap(ans[i] , ans[random]);
        }
        
        return ans;
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */