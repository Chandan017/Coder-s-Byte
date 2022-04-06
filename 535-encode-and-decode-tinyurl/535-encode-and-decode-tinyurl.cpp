class Solution {
private:
    map<string,string> mpp;
    int val = 0;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        
        val++ ;
        string tinyUrl = "http://tinyurl.com/" + to_string(val);
        mpp[tinyUrl] = longUrl;
        
        cout<<tinyUrl<<endl;
        return tinyUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        
        cout<<mpp[shortUrl]<<endl;
        return mpp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));