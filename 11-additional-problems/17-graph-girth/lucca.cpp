#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
#define int long long
 
using namespace std;
 
const int maxn = 2e5 + 10, inf = 2e9, M = 1e9 + 7;
 
vector<int> adj[maxn];
 
bool vis[maxn];
int dist[maxn], ans = inf;
 
void bfs(int x) {
	queue<pair<int, int>> q;
	q.push({x, x});
	memset(vis, 0, sizeof(vis));
	vis[x] = true;
	dist[x] = 0;
	while (!q.empty()) {
		auto [s, e] = q.front(); q.pop();
		for (int u : adj[s]) {
			if (vis[u]) {
				if (u != e)
					ans = min(ans, dist[u] + dist[s] + 1);
				continue;
			}
			vis[u] = true;
			dist[u] = dist[s] + 1;
			q.push({u, s});
		}
	}
}
 
void solve() {
	int n, m; cin >> n >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	for (int i = 1; i <= n; ++i) {
		bfs(i);
	}
	if (ans == inf) cout << "-1\n";
	else cout << ans << endl;
}
 
signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}