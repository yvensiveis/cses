/**
 Ideia:
 * Def. pref[i] := v[0] ^ v[1] ^ ... ^ v[i]
 * pref[a-1] = v[0] ^ v[1] ^ ... ^ v[a-1]
 * pref[b] = v[0] ^ v[1] ^ ... ^ v[b]
 * pref[a-1] ^ pref[b] = (v[0] ^ v[1] ^ ... ^ v[a-1]) ^ (v[0] ^ v[1] ^ ... ^ v[a-1]) ^ (v[a] ^ ... ^ v[b])
 *                     = 0 ^ (v[a] ^ v[b])
 *                     = v[a] ^ v[b]
**/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long int ll;

const int MAXN = 1e5 + 10, INF = 2e9, M = 1e9 + 7;

void solve() {
	int n, q; cin >> n >> q;
	vector<int> pref(n+1);
	for (int i = 1; i <= n; ++i) {
		int x; cin >> x;
		pref[i] = pref[i-1] ^ x;
	}
	while (q--) {
		int a, b; cin >> a >> b;
		cout << (pref[b] ^ pref[a-1]) << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}