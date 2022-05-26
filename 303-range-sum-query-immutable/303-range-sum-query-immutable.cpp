class NumArray {
public:
    
    vector<int> sum;
    NumArray(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++)
        {
            if(i==0)
                sum.push_back(nums[i]);
            else
            {
                int val = sum[sum.size()-1] + nums[i];
                sum.push_back(val);
            }
        }
        
    }
    
    int sumRange(int left, int right) {
        
        int val = sum[right];
        if(left != 0)
            val -= sum[left-1];
        
        return val;
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */