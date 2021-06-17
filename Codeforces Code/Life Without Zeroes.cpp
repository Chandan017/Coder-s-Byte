#include <bits/stdc++.h>
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mk make_pair
#define pb push_back 
#define fi first
#define se second
const int INF = 0x3f3f3f3f;

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

int nz(int x) {
	int pot=1;
	int ret=0;
	for(;x;x/=10) {
		ret+=(x%10) * pot;
		if(x%10)pot*=10;
	}
	return ret;
}

int main(){
        ios::sync_with_stdio(false);
	int a,b,c;
	cin>>a>>b;
	c=a+b;
	//cout << nz(a) << " " << nz(b) << "\n";
	if(nz(c)==nz(a)+nz(b))
		cout<<"YES\n";
	else cout<<"NO\n";

        return 0;
}
