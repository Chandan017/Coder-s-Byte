//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    string getBinary(int num)
    {
        string res = "";
        
        while(num)
        {
            if(num%2 == 1)
                res += '1';
            else
                res += '0';
            
            num /= 2;
        }
        reverse(res.begin() , res.end());
        return res;
    }
    
    int getBitCnt(int num)
    {
        int cnt= 0;
        
        while(num)
        {
            if(num%2 == 1)
                cnt++;
            
            num /= 2;
        }
        
        return cnt;
    }
    int minVal(int a, int b) {
        
        string aBin = getBinary(a);
        int setBitCnt = getBitCnt(b);
        string res = "";
        
        for(int i=0;i<aBin.length();i++)
        {
            if(aBin[i] == '1' && setBitCnt)
            {
                res += '1';
                setBitCnt--;
            }
            else
                res += '0';
        }
        
        for(int i=res.length()-1;i>=0 && setBitCnt>0 ; i--)
        {
            if(res[i] == '0')
            {
                res[i] = '1';
                setBitCnt--;
            }
        }
        
        int x = stoi(res , 0 , 2);
        
        return x;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends