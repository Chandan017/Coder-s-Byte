#include <bits/stdc++.h>
using namespace std;

long long k, l, cnt, now;

int main() {
  ios_base::sync_with_stdio(0);

  cin >> k >> l;

  now = k;
  while(now < l) {
    now *= k; ++cnt;
  }

  if(now == l) cout << "YES\n" << cnt << '\n';
  else cout << "NO\n";

  return 0;
}