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
        
        return tinyUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        
        return mpp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));