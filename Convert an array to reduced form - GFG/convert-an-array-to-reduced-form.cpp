//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Converts arr[0..n-1] to reduced form.
	void convert(int arr[], int n) {
	    // code here
	    
	    vector<int> nums;
	    
	    for(int i=0;i<n;i++)
	    {
	        nums.push_back(arr[i]);
	    }
	    
	    sort(nums.begin() , nums.end());
	    
	    for(int i=0;i<n;i++)
	    {
	        int ind = lower_bound(nums.begin() , nums.end() , arr[i]) - nums.begin();
	        arr[i] = ind;
	    }
	    
	    return ;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.convert(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends