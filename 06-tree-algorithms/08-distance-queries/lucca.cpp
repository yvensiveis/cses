#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long int ll;

const int MAXN = 2e5 + 10, M = 1e9 + 7, INF = 2e9, LOG = 25;

int depth[MAXN], anc[MAXN][LOG];

vector<int> adj[MAXN];

void dfs(int s, int p) {
	depth[s] = depth[p] + 1;
	anc[s][0] = p;
	for (int i = 1; i < LOG; ++i)
		anc[s][i] = anc[anc[s][i-1]][i-1];
	for (int u : adj[s])
		if (u != p)
			dfs(u, s);
}

int lca(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);
	int k = depth[a] - depth[b];
	for (int i = 0; i < LOG; ++i)
		if (k & (1 << i))	
			a = anc[a][i];
	if (a == b) return a;
	for (int i = LOG - 1; i >= 0; --i) {
		if (anc[a][i] == anc[b][i]) continue;
		a = anc[a][i];
		b = anc[b][i];
	}
	return anc[a][0];
}

int dist(int a, int b) {
	return depth[a] + depth[b] - 2*depth[lca(a, b)];
}

void solve() {
	int n, q; cin >> n >> q;
	for (int i = 0; i < n-1; ++i) {
		int a, b; cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(1, 0);
	while (q--) {
		int a, b; cin >> a >> b;
		cout << dist(a, b) << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}