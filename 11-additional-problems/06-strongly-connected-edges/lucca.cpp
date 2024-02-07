#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define pc __builtin_popcount
#define int long long
 
using namespace std;
 
const int maxn = 2e5 + 10, inf = 1e18, M = 1e9 + 7;
 
vector<pair<int, int>> adj[maxn];
 
int tin[maxn], low[maxn], vis[maxn], timer, tem_ponte;
 
vector<pair<int, int>> ans;
 
void dfs(int s, int p) {
	tin[s] = low[s] = ++timer;
	for (auto [u, e] : adj[s]) {
		if (!vis[e])
			ans.pb({s, u});
		vis[e] = true;
		if (!tin[u]) {
			dfs(u, s);
			low[s] = min(low[s], low[u]);
			if (low[u] > tin[s])
				tem_ponte = true;
		} else if (u != p) {
			low[s] = min(low[s], tin[u]);
		}
	}
}
 
void solve() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		adj[a].pb({b, i});
		adj[b].pb({a, i});
	}
	dfs(1, 1);
	for (int i = 1; i <= n; ++i)
		if (!tin[i]) {
			cout << "IMPOSSIBLE\n";
			return;
		}
	if (tem_ponte) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	for (auto [a, b] : ans) {
		cout << a << ' ' << b << endl;
	}
}
 
signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	solve();
}