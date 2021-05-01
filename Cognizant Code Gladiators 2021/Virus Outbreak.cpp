#include<bits/stdc++.h>
using namespace std;

bool isSubSequence(string str1, string str2,int m, int n)
{
     
    
    int j = 0; 
    for (int i = 0; i < n && j < m; i++)
        if (str1[j] == str2[i])
            j++;
    return (j == m);
}

int main(int argc, char *a[])
{
    string str1;
    int t;
    cin>>str1>>t;
    while(t--)
    {
        string str2;
        cin>>str2;
        int m=str2.length();
        int n=str1.length();
        if(isSubSequence(str2,str1,m,n)==true)
            cout<<"POSITIVE"<<endl;
        else
            cout<<"NEGATIVE"<<endl;   



    }
    return 0;

    
}