class DataStream {
public:
    

    int n , val , ind = 0 , prev = 0;
    DataStream(int value, int k) {
        
        n = k;
        val = value;
    }
    
    bool consec(int num) {
        
        ind++;
        
        if(num != val)
        {
            prev = ind;
            return false;
        }
        
        if(ind-prev < n)
            return false;
        return true;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */