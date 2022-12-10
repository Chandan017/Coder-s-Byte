class Logger {
public:
    
    unordered_map<string,int> mpp;
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        
        if(mpp.find(message) != mpp.end())
        {
            if(mpp[message]+10 <= timestamp)
            {
                mpp[message] = timestamp;
                return true;
            }
            return false;
        }
        
        mpp[message] = timestamp;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */