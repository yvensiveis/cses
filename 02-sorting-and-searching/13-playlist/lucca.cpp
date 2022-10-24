#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount

using namespace std;

typedef long long int ll;

const int MAXN = 2e5 + 10, INF = 2e9, M = 1e9 + 7;

// 2P ftw
void solve() {
	int n; cin >> n;
	vector<int> v(n);
	for (int &x : v) cin >> x;
	int l = 0, r = 0;
	int ans = 1;
	map<int, int> freq;
	freq[v[0]]++;
	while (r+1 < n) {
		while (freq[v[r+1]])
			freq[v[l++]]--;
		freq[v[++r]]++;
		ans = max(ans, r-l+1);
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}