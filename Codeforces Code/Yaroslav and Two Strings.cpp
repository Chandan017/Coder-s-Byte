#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz(x) ((int)(x).size())
#define rep(i,l,r) for(int i=(l);i<(r);++i)
//-------
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;
int n;
char s[N], t[N];
void inc(int &x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
}
int solve(char s[], char t[]) {
	int ret = 1;
	rep(i, 0, n)
		if (s[i] == '?') {
			if (t[i] == '?') {
				ret = 1ll * ret * 55 % MOD;
			} else {
				ret = 1ll * ret * (t[i] - '0' + 1) % MOD;
			}
		} else {
			if (t[i] == '?') {
				ret = 1ll * ret * (10 - (s[i] - '0')) % MOD;
			} else {
				if (s[i] > t[i])
					return 0;
			}
		}
	return ret;
}
int equal(char s[], char t[]) {
	int ret = 1;
	rep(i, 0, n) 
		if (s[i] == '?') {
			if (t[i] == '?')
				ret = 1ll * ret * 10 % MOD;
		} else {
			if (t[i] != '?' && s[i] != t[i])
				return 0;
		}
	return ret;
}
int main() {
	scanf("%d %s %s", &n, s, t);
	int ans = 1;
	rep(i, 0, n) {
		ans = 1ll * ans * (s[i] == '?' ? 10 : 1) % MOD;
		ans = 1ll * ans * (t[i] == '?' ? 10 : 1) % MOD;
	}
	inc(ans, MOD - solve(s, t));
	inc(ans, MOD - solve(t, s));
	inc(ans, equal(s, t));
	printf("%d", ans);
	return 0;
}
