#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
 
using namespace std;
 
typedef long long int ll;
 
const int MAXN = 2e5 + 10, INF = 2e9, M = 1e9 + 7, LOG = 30;
 
int anc[MAXN][LOG];
 
void solve() {
	int n, q; cin >> n >> q;
	for (int i = 2; i <= n; ++i)
		cin >> anc[i][0];
	anc[1][0] = 0;
	for (int i = 1; i < LOG; ++i)
		for (int u = 1; u <= n; ++u)
			anc[u][i] = anc[anc[u][i-1]][i-1];
	while (q--) {
		int x, k; cin >> x >> k;
		for (int i = 0; i < LOG; ++i)
			if (k & (1 << i))
				x = anc[x][i];
		cout << (x ? x : -1) << endl;
	}
}
 
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}