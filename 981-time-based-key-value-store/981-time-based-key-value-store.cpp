class TimeMap {
public:
    map<pair<string,int> , string> mpp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        
        mpp[{key , timestamp}] = value;
    }
    
    string get(string key, int timestamp) {
        
        while(timestamp>0)
        {
            if(mpp.find({key,timestamp}) != mpp.end())
                return mpp[{key , timestamp}];
            timestamp--;
        }
        
        return "";
        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */