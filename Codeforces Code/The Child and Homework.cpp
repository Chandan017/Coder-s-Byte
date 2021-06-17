#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e6 + 100;
int val[maxn];
ll res = 0;

int main(){
    ios::sync_with_stdio(false);

    string s[4];
    cin >> s[0] >> s[1] >> s[2] >> s[3];

    pair<int, char> l[4];
    for(int i = 0; i < 4; i++){
    	l[i].first = s[i].size() - 2;
    	l[i].second = 'A' + i;
    }
    sort(l, l + 4);

    bool agood = l[0].first * 2 <= l[1].first;
    bool bgood = l[2].first * 2 <= l[3].first;

    if(agood == bgood){
		cout << 'C';
    } else if(agood){
    	cout << l[0].second;
    } else if(bgood){
    	cout << l[3].second;
    }

}
