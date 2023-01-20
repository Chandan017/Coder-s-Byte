//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int N, vector<int> Edge)
  {
      // code here
      int maxi = 0;
      vector<int> sum(N,0);
      
      for(int i=0;i<N;i++)
      {
          if(Edge[i] == -1)
            continue;
          sum[Edge[i]] += i;
          
          maxi = max(maxi , sum[Edge[i]]);
      }
      
      if(maxi == 0)
        return 0;
    
    int res;
    for(int i=0;i<N;i++)
    {
        if(sum[i] == maxi)
            res = i;
    }
    
    return res;
  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends