class Solution {
public:

    map<string , string> mpp;
    int val = 0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        
        string shortUrl = longUrl + to_string(val);
        
        mpp[shortUrl] = longUrl;
        val++;
        
        return shortUrl;
        
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        
        
        return mpp[shortUrl];
        
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));