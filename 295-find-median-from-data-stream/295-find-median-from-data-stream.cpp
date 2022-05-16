class MedianFinder {
public:
    
    priority_queue<int> small ;
    priority_queue<int , vector<int> , greater<int> > large;
    MedianFinder() {
        
    }
    
    bool sizeCheck(int smallLen  , int largeLen)
    {
        
        if(abs(smallLen - largeLen) <=1)
            return true;
        return  false;
    }
    
    void fixSize(int smallLen , int largeLen)
    {
        
        int val = small.top();
        small.pop();
        large.push(val);        
        return ;
    }
    
    bool valCheck(int smallLen , int largeLen)
    {
       
        if(smallLen==0 || largeLen==0)
            return true;
        
        int smallVal = small.top();
        int largeVal = large.top();
        
        if(smallVal > largeVal)
            return false;
        
        return true;
    }
    
    void fixVal(int smallLen , int largeLen)
    {
       
        
        if(smallLen == largeLen)
        {
            int smallVal = small.top();
            small.pop();
            large.push(smallVal);
            
            int largeVal = large.top();
            large.pop();
            small.push(largeVal);
        }
        else
        {
            int smallVal = small.top();
            small.pop();
            large.push(smallVal);
       }
        
        return ;
    }
    
    void addNum(int num) {
        
        small.push(num);
        
        int smallLen = small.size();
        int largeLen = large.size();
        
        if(sizeCheck(smallLen , largeLen) == false)
            fixSize(smallLen , largeLen);
        
      
         if(valCheck(smallLen , largeLen) == false)
         {
             fixVal(smallLen , largeLen);
         }
 
        
    }
    
    double findMedian() {
        
        int smallLen = small.size();
        int largeLen = large.size();
        
        if(smallLen == largeLen)
        {
            double firstVal = (double)small.top();
            double secondVal = (double)large.top();
            
            double ans = (firstVal + secondVal) / 2.00;
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