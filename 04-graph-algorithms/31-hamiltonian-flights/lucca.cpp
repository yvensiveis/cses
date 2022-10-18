/*
dp[i][j]: quantidade de caminhos de i a n
tendo visitado os vertices em j (bitmask)
maldita seja a dp iterativa
recorrencia:
dp(s, mask) = sum(dp(u, mask | (1 << s))) for u in adj[s], u not in mask
*/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount

using namespace std;

typedef long long int ll;

const int MAXN = 21, INF = 2e9, M = 1e9 + 7;

vector<int> rev[MAXN];

int n, m, dp[MAXN][1 << MAXN];

void solve() {
	cin >> n >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		rev[b].pb(a);
	}
	int msk = 0;
	for (int i = 1; i < n; ++i) msk |= (1 << i);
	dp[n][msk] = 1;
	for (int mask = msk; mask >= 0; --mask)
		for (int s = n; s >= 1; --s)
			if (dp[s][mask])
				for (int u : rev[s])
					if (mask & (1 << u))
						dp[u][mask & ~(1 << u)] = (dp[u][mask & ~(1 << u)] + dp[s][mask]) % M;
	cout << dp[1][0] << endl;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}