class RandomizedSet {
public:
    unordered_map<int,int> mpp;
    vector<int> nums;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        
        if(mpp.find(val) != mpp.end())
            return false;
        
        nums.push_back(val);
        mpp[val] = nums.size()-1;
        
        return true;
    }
    
    bool remove(int val) {
        
        if(mpp.find(val) != mpp.end())
        {
            if(nums.back() != val)
            {
                int ind = mpp[val];
                nums[ind] = nums.back();
                mpp[nums.back()] = ind;  
            }
            mpp.erase(val);
            nums.pop_back();
            
            return true;
        }
        
        return false;
    }
    
    int getRandom() {
        
        int n = nums.size();
        int curr = nums[rand()%n];
        return curr;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */