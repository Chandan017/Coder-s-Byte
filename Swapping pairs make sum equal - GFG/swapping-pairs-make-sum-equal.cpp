// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	
	int getSum(int A[] , int n)
	{
	    
	    int sum = 0;
	    for(int i=0;i<n;i++)
	        sum += A[i];
	    return sum;
	}
	int findSwapValues(int A[], int n, int B[], int m)
	{
        // Your code goes here
        
        sort(A,A+n);
        sort(B,B+m);
        
        int ASum = getSum(A,n);
        int BSum = getSum(B,m);
        
        if((ASum - BSum) %2 != 0)
            return -1; 
        
        int target = (ASum - BSum) /2 ;
        
        int i=0,j=0;
        
        while(i<n && j<m)
        {
            int currDiff = A[i] - B[j];
            
            if(currDiff == target)
                return 1;
            else if(currDiff < target)
                i++;
            else
                j++;
        }
        
        return -1;
        
        
	}
 

};

// { Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        

        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    }
    return 0;
}





  // } Driver Code Ends