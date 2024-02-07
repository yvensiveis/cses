#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define pc __builtin_popcount
#define int long long
 
using namespace std;
 
const int maxn = 2e5 + 10, inf = 1e18, M = 1e9 + 7, LOG = 30;
 
vector<int> adj[maxn];
 
int timer = 1, lo[maxn], tin[maxn], tout[maxn], anc[maxn][LOG], depth[maxn];
 
void dfs(int s) {
    tin[s] = timer++;
    lo[s] = tin[s];
    for (int u : adj[s]) {
        if (!tin[u]) {
            anc[u][0] = s;
			depth[u] = depth[s] + 1;
            dfs(u);
            lo[s] = min(lo[s], lo[u]);
        } else
            lo[s] = min(lo[s], tin[u]);
    }
    tout[s] = timer;
}
 
int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    int k = depth[a] - depth[b];
    for (int i = 0; i < LOG; ++i)
        if (k & (1 << i))
            a = anc[a][i];
    if (a == b) return a;
    for (int i = LOG-1; i >= 0; --i) {
        if (anc[a][i] == anc[b][i]) {
            continue;
        }
        a = anc[a][i];
        b = anc[b][i];
    }
    return anc[a][0];
}
 
void tc(int a, int b, int c, int t) {
	if (a == c || b == c) { cout << "NO\n"; return; }
	if (a == b) { cout << "YES\n"; return; }
 
	int l = lca(a, b);
 
	if (l == a || l == b) { // A é ancestral de B
		if (tin[a] > tin[b]) swap(a, b);
		if (lca(b, c) == c && lca(a, c) == a) { // C está entre A e B
			int lucca = b;
			for (int i = LOG-1; i >= 0; --i)
				if (depth[anc[lucca][i]] > depth[c])
					lucca = anc[lucca][i];
			assert(depth[lucca] == depth[c] + 1);
			if (lo[lucca] < tin[c]) { cout << "YES\n"; return; }
			else { cout << "NO\n"; return; }
		} else { // C nao esta entre A e B
			cout << "YES\n";
			return;
		}
	}
 
	if (l == c) { // C é o LCA de A e B
		int lucca = a, pietra = b;
		for (int i = LOG-1; i >= 0; --i) {
			if (depth[anc[lucca][i]] > depth[c])
				lucca = anc[lucca][i];
			if (depth[anc[pietra][i]] > depth[c])
				pietra = anc[pietra][i];
		}
		assert(depth[lucca] == depth[c] + 1);
		assert(depth[pietra] == depth[c] + 1);
		if (lo[lucca] < tin[c] && lo[pietra] < tin[c]) {
			cout << "YES\n"; return;
		} else {
			cout << "NO\n"; return;
		}
	}
 
	int lucca = -1;
 
	if (lca(a, c) == c && lca(c, l) == l) // C está entre A e L
		lucca = a;
	else if (lca(b, c) == c && lca(c, l) == l) // C está entre B e L
		lucca = b;
 
	if (lucca == -1) {
		cout << "YES\n";
		return;
	} else {
		for (int i = LOG-1; i >= 0; --i)
			if (depth[anc[lucca][i]] > depth[c])
				lucca = anc[lucca][i];
		assert(depth[lucca] == depth[c] + 1);
		if (lo[lucca] < tin[c]) cout << "YES\n";
		else cout << "NO\n";
		return;
	}	
	cout << a << ' ' << b << ' ' << c << endl;
	assert(false);
}
 
void solve() {
	int n, m, q; cin >> n >> m >> q;
	while (m--) {
		int a, b; cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(1);
	for (int i = 1; i < LOG; ++i)
        for (int s = 1; s <= n; ++s)
            anc[s][i] = anc[anc[s][i-1]][i-1];
	for (int i = 1; i <= q; ++i) {
		int a, b, c; cin >> a >> b >> c;
		tc(a, b, c, i);
	}
}
 
signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	solve();
}