//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ll long long


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long

	ll countSubarray(int arr[], int n, int k) {
	    // code here
	    
	    ll res = n;
	    
	    res = (res*(res+1))/2;
	    ll cnt = 0;
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i] > k)
	        {
	            cnt = (cnt*(cnt+1))/2;
	            
	            res -= cnt;
	            
	            cnt = 0;
	        }
	        else
	            cnt++;
	        
	    }
	    
	    if(cnt > 0)
	    {
	        cnt = (cnt*(cnt+1))/2;
	            
	        res -= cnt;
	    }
	    
	    return res;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.countSubarray(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends