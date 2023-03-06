//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
    int noConseBits(int n) {
        // code here
        
        string s = bitset<64> (n).to_string();
        int len = s.length() , i = 0;
        while(i<len-2)
        {
            if(s[i] == '1' && s[i+1] == '1' && s[i+2] == '1')
            {
                s[i+2] = '0';
                i += 3;
            }
            else
                i++;
        }
        
        // cout<<s<<endl;
        
        int res = stoi(s, 0, 2);
        
        
        return res;
        
    }
};


//{ Driver Code Starts.

int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        int ans = sol.noConseBits(n);
        cout << ans << '\n';
    }

    return 0;
}

// } Driver Code Ends