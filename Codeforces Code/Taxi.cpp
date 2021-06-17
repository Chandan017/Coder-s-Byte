#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int n;
int T[100002];

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", &T[i]);
	sort(T, T + n, greater<int>());
	
	int r = 0, p = 0, k = n - 1;
	while(T[p] == 4) ++p, ++r;
	while(T[p] == 3 && T[k] == 1) ++p, --k, ++r;
	while(p <= k && T[p] == 3) ++p, ++r;
	while(p <= k && T[p] == 2 && T[p + 1] == 2) p += 2, ++r;
	if(p <= k && T[p] == 2) p += 3, ++r;
	while(p <= k) p += 4, ++r;
	
	printf("%d\n", r);
	return 0;
}
