class SparseVector {
public:
    vector<int> temp;
    SparseVector(vector<int> &nums) {
        
        temp = nums;
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        
        int res = 0;
        
        for(int i=0;i<temp.size();i++)
        {
            if(vec.temp[i] == 0 || temp[i] == 0)
                continue;
            else
            {
                res = res + (temp[i]*vec.temp[i]);
            }
        }
        
        return res;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);