#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz(x) ((int)(x).size())
#define rep(i,l,r) for(int i=(l);i<(r);++i)
//-------
const int N = 1007;
int n, a[N], c[N];
bool solve() {
	rep(i, 0, n) {
		scanf("%d", &a[i]);
		++c[a[i]];
	}
	int lim = (n + 1) >> 1;
	rep(i, 0, n)
		if (c[a[i]] > lim)
			return false;
	return true;
}
int main() {
	scanf("%d", &n);
	puts(solve() ? "YES" : "NO");
	return 0;
}
