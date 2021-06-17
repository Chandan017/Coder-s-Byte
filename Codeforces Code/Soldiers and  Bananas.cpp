#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,n) for(int i=1;i<=n;i++)
int main(){
    long long k,n,w;
    cin >> k >> n >> w;
    cout << max(0LL,w*(w+1)/2*k-n) << endl;
}