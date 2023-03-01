class ProductOfNumbers {
public:
    
    vector<int> prefix = {1};
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        
        if(num == 0)
            prefix = {1};
        else
            prefix.push_back(prefix.back()*num);
    }
    
    int getProduct(int k) {
        
        if(k >= prefix.size())
            return 0;
        
        int res = prefix.back()/prefix[prefix.size()-k-1];
        return res;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */