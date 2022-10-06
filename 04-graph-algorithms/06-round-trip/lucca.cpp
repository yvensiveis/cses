/**
Encontrar um ciclo em grafo nao
direcionado
**/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
 
using namespace std;
 
typedef long long int ll;
 
const int MAXN = 1e5 + 10, INF = 2e9, M = 1e9 + 7;
 
vector<int> adj[MAXN];
int par[MAXN], start;
bool found_cycle = false, vis[MAXN];
 
void dfs(int s, int p) {
	if (found_cycle) return;
	if (vis[s]) {
		found_cycle = true;
		par[s] = p;
		start = s;
		return;
	}
	vis[s] = true;
	par[s] = p;
	for (int u : adj[s]) {
		if (u == p) continue;
		dfs(u, s);
	}
}
 
void solve() {
	int n, m; cin >> n >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) dfs(i, i);
		if (found_cycle) break;
	}
	if (!found_cycle) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	vector<int> ans;
	ans.pb(start);
	int u = par[start];
	while (u != start) {
		ans.pb(u);
		u = par[u];
	}
	ans.pb(start);
	cout << ans.size() << endl;
	for (int s : ans) 
		cout << s << ' ';
	cout << endl;
}
 
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}