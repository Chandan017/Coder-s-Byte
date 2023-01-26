//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
  
        string reverseWithSpacesIntact (string s)
        {
            
            string temp = "";
            for(auto it:s)
            {
                if(it != ' ')
                    temp += it;
            }
            
            for(auto &it:s)
            {
                if(it != ' ')
                {
                    it = temp.back();
                    temp.pop_back();
                }
            }
            
            return s;
        }
      

};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    cin.ignore ();
    while (t--)
    {
        string s;
        getline (cin, s);
        Solution ob;
        cout << ob.reverseWithSpacesIntact (s) << endl;
    }
    return 0;
}
// Contributed By: Pranay Bansal

// } Driver Code Ends