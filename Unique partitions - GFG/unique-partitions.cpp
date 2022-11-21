//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	vector<vector<int>> res;
	void solve(int sum , int currSum , int currNum , vector<int> &path)
	{
	    if(currNum < 1 || currSum > sum)
	        return ;
	    
	    if(currSum == sum)
	    {
	        res.push_back(path);
	        return ;
	    }
	    
	    for(int i=currNum ;i>0;i--)
	    {
	        path.push_back(i);
	        currSum += i;
	        
	        solve(sum , currSum , i , path);
	        
	        path.pop_back();
	        currSum -= i;
	    }
	    
	    return ;
	}
    vector<vector<int>> UniquePartitions(int n) {
        // Code here
        
        vector<int> path;
        
        solve(n , 0 , n , path);
        
        return res;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		vector<vector<int>> ans = ob.UniquePartitions(n);
    	for(auto i : ans)
    		for(auto j: i)
    			cout << j <<" ";
    	cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends