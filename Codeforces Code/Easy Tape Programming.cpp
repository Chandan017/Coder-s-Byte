#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n';
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define floop(i,a,b) for(int i=a;i<=b;++i)
const ll mod=1e9+7;
void f(string s){
	int n=s.size();
	vector<int>ans(10,0);
	vector<bool>active(n,1),ischar(n,0);
	for (int i = 0; i < n; ++i)
	{
		if(s[i]=='<' or s[i]=='>') ischar[i]=1;
	}
	int i=0,prev=-1,d=1;
	while(i>=0 and i<n){
		if(!active[i]){
			i+=d;
			continue;
		}
		if(ischar[i]){
			if(prev!=-1 and ischar[prev]) active[prev]=0;
			if(s[i]=='<') d=-1;
			else d=1;
		}
		else{
			ans[s[i]-'0']++;
			if(s[i]=='0') active[i]=0;
			else s[i]--;
		}
		prev=i;
		i+=d;
	}
	for ( i = 0; i < 10; ++i)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}
int main(){
	IOS;
	int n,q;
	cin>>n>>q;
	string s;
	cin>>s;
	while(q--){
		int l,r;
		cin>>l>>r;
		l--,r--;
		f(s.substr(l,r-l+1));
	}
	return 0;
}