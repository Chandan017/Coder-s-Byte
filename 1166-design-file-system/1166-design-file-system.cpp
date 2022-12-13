class FileSystem {
public:
    unordered_map<string,int> mpp;
    FileSystem() {
        
    }
    
    bool createPath(string path, int value) {
        
        if(mpp.find(path) != mpp.end())
            return false;
        
        string curr = path;
        while(path.back() != '/')
        {
            path.pop_back();
        }
        
        path.pop_back();
        
        if(path.size() > 1)
        {
            if(mpp.find(path) == mpp.end())
                return false;
        }

        mpp[curr] = value;
        return true;
        
    }
    
    int get(string path) {
        
        if(mpp.find(path) == mpp.end())
            return -1;
        
        return mpp[path];
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */