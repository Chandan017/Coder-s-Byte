#include <bits/stdc++.h>
using namespace std;

const int dx[5] = { 0, 1, 1, 1, 2 };
const int dy[5] = { 0, -1, 0, 1, 0 };

bool check(vector<string> &mat, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] == '.') continue;
			if (j <= 0 || j >= n - 1 || i >= n - 2) return 0;
			for (int d = 0; d < 5; d++) {
				if (mat[i + dx[d]][j + dy[d]] == '.') return 0;
				mat[i + dx[d]][j + dy[d]] = '.';
			}
		}
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	int n;
	while (cin >> n) {
		vector<string> mat(n);
		for (int i = 0; i < n; i++) cin >> mat[i];
		cout << (check(mat, n) ? "YES" : "NO") << endl;
	}
	return 0;
}
