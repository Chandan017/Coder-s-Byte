//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int R, int C, vector<vector<int>>&nums)  {
        // code here
        
        int left = 0 , right = C-1 , top = 0 , down = R-1;
        vector<int> res;
        int dir = 1;
        while(res.size() < (R*C))
        {
            if(dir == 1)
            {
                for(int i=left;i<=right;i++)
                {
                    res.push_back(nums[top][i]);
                }
                top++;
                dir = 2;
            }
            else if(dir == 2)
            {
                for(int i=top;i<=down;i++)
                {
                    res.push_back(nums[i][right]);
                }
                
                right--;
                dir = 3;
            }
            else if(dir == 3)
            {
                for(int i=right;i>=left;i--)
                {
                    res.push_back(nums[down][i]);
                }
                
                down--;
                dir = 4;
            }
            else if(dir == 4)
            {
                for(int i=down;i>=top;i--)
                {
                    res.push_back(nums[i][left]);
                }
                left++;
                dir = 1;
            }
            
        }
        
        reverse(res.begin() , res.end());
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends