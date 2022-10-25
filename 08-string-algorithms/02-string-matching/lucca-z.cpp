#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount

using namespace std;

typedef long long int ll;

const int MAXN = 1e5 + 10, INF = 2e9, M = 1e9 + 7;

vector<int> z_func(string s) {
	int n = s.size(), l = 0, r = 0;
	vector<int> res(n);
	for (int i = 1; i < n; ++i) {
		bool lucca = false;
		if (i > r) {
			l = r = i;
			lucca = true;
		} else {
			int k = i-l;
			if (res[k] < r-i+1) res[i] = res[k];
			else {l = i; lucca = true;}
		}
		if (lucca) {
			while (r < n && s[r-l] == s[r]) ++r;
			res[i] = r-l, --r;
		}
	}
	return res;
}

void solve() {
	string s, a; cin >> s >> a;
	int n = s.size(), m = a.size();
	string aux = a + '#' + s;
	vector<int> z = z_func(aux);
	int ans = 0;
	for (int i = m+1; i < n+m+1; ++i) {
		ans += z[i] == m;
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}