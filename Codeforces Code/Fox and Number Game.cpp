#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	int n;
	while (cin >> n) {
		int x = 0, y;
		for (int i = 0; i < n; i++) {
			cin >> y;
			x = __gcd(x, y);
		}
		cout << x * n << endl;
	}
	return 0;
}