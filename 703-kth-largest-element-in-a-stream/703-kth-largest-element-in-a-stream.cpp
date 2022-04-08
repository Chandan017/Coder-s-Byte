class KthLargest {
public:
    
    priority_queue<int , vector<int> , greater<int>> pq;
    int kth ;
    KthLargest(int k, vector<int>& nums) {
        
        for(auto it:nums)
        {
            pq.push(it);
            
            if(pq.size() > k)
                pq.pop();
        }
        
        kth = k;
    }
    
    int add(int val) {
        
        pq.push(val);
        
        if(pq.size() > kth)
            pq.pop();
        
        return pq.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */