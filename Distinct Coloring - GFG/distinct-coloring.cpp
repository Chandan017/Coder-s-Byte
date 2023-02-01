//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:

    long long int solve(int ind , int N , int r[] , int g[] , int b[] , int prev , vector<vector<long long int>> &dp)
    {
        if(ind == N)
            return 0;
            
        if(dp[ind][prev] != -1)
            return dp[ind][prev];
        
        long long int red = 1e11; 
        long long int blue = 1e11;
        long long int green = 1e11;
        
        if(prev == 0)
        {
            red = r[ind] + solve(ind+1 ,N, r , g, b, 1 ,dp);
            green = g[ind] + solve(ind+1 ,N, r, g, b , 2,dp);
            blue = b[ind] + solve(ind+1 , N,r , g, b , 3,dp);
        }
        else if(prev == 1)
        {
            green = g[ind] + solve(ind+1 , N , r , g , b , 2,dp);
            blue = b[ind] + solve(ind+1 , N , r , g , b , 3,dp);
        }
        else if(prev == 2)
        {
            red = r[ind] + solve(ind+1 , N , r , g , b , 1,dp);
            blue = b[ind] + solve(ind+1 , N , r , g , b , 3,dp);
        }
        else
        {
            red = r[ind] + solve(ind+1 , N , r , g , b , 1,dp);
            green = g[ind] + solve(ind+1 , N , r , g , b , 2,dp);
        }
        
        return dp[ind][prev] = min(red , min(green , blue));
       
    }
    long long int distinctColoring(int N, int r[], int g[], int b[]){
        // code here 
        vector<vector<long long int>> dp(N+1 , vector<long long int> (4,-1));
        long long int res = solve(0 , N , r , g , b, 0,dp);
        
        return res;
        
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends