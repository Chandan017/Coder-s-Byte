class DataStream {
public:
    
    queue<int> q;
    int n , val , diffCnt = 0;
    DataStream(int value, int k) {
        
        n = k;
        val = value;
    }
    
    bool consec(int num) {
        
        if(num != val)
            diffCnt++;
        
        q.push(num);
        
        if(q.size() > n)
        {
            int curr = q.front();
            q.pop();
            if(curr != val)
                diffCnt--;
        }
        
        if(q.size() < n || diffCnt)
            return false;
        
        
        return true;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */