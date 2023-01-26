//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        
        string lowercase = "" , uppercase = "";
        
        for(auto it:str)
        {
            if(isupper(it))
                uppercase += it;
            else
                lowercase += it;
        }
        
        sort(lowercase.begin() , lowercase.end());
        sort(uppercase.begin() , uppercase.end());
        
        int j = 0 , k = 0;
        for(int i=0;i<n;i++)
        {
            if(isupper(str[i]))
                str[i] = uppercase[j++];
            else
                str[i] = lowercase[k++];
        }
        
        return str;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends