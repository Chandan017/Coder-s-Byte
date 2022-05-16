class MedianFinder {
public:
    
    priority_queue<int> small ;
    priority_queue<int , vector<int> , greater<int> > large;
    MedianFinder() {
        
    }
    
    
    void fixSize(int smallLen , int largeLen)
    {
       
        
    }
    
   
    
    
    void addNum(int num) {
        
        if(small.size()==0 || num <= small.top())
            small.push(num);
        else
            large.push(num);
    
        int smallLen = small.size();
        int largeLen = large.size();
        
        if(smallLen > (largeLen + 1))
        {
            large.push(small.top());
            small.pop();
        }
        else if((smallLen+1) < largeLen)
        {
            small.push(large.top());
            large.pop();
        }
        
    }
    
    double findMedian() {
        
        int smallLen = small.size();
        int largeLen = large.size();
        
        if(smallLen == largeLen)
        {
        
            double ans = (small.top() + large.top()) / 2.00;
            return ans;
        }
        else
        {
            double ans;
            if(smallLen > largeLen)
                ans = (double)small.top();
            else
                ans = (double)large.top();
            
            return ans;
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */