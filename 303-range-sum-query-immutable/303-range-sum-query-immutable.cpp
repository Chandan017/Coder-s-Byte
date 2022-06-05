class NumArray {
public:
    vector<int> prefix;
    NumArray(vector<int>& nums) {
        
        long sum = 0;
        for(auto it:nums)
        {
            sum += it;
            prefix.push_back(sum);
        }
        
    }
    
    int sumRange(int left, int right) {
        
        int val = prefix[right];
        if(left!=0)
            val -= prefix[left-1];
        
        return val;
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */