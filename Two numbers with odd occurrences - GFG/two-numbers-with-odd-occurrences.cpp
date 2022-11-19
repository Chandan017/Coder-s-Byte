//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        
        long long int curr = 0;
        
        for(long long int i=0;i<N;i++)
        {
            curr ^= Arr[i];
        }
        
    
        long long int mask = 1;
        while((curr & mask) == 0)
        {
            mask = mask<<1;
        }
        
        
        vector<long long int> res(2 , 0);
        
        
        for(long long int i=0;i<N;i++)
        {
            if((Arr[i] & mask) == 0)
                res[0] ^= Arr[i];
            else
                res[1] ^= Arr[i];
        }
        
        
        if(res[0] < res[1])
            swap(res[0] , res[1]);
            
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
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends