/**
BFS com reconstrucao do
caminho minimo
**/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount

using namespace std;

typedef long long int ll;

const int MAXN = 1e5 + 10, INF = 2e9, M = 1e9 + 7;

vector<int> adj[MAXN];

int dist[MAXN], par[MAXN];
bool vis[MAXN];

void bfs(int x) {
	queue<int> q;
	q.push(x);
	par[x] = x;
	while (!q.empty()) {
		int s = q.front(); q.pop();
		for (int u : adj[s]) {
			if (vis[u]) continue;
			vis[u] = true;
			dist[u] = dist[s] + 1;
			par[u] = s;
			q.push(u);
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
	bfs(1);
	if (!vis[n]) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	cout << dist[n] + 1 << '\n';
	int u = n;
	vector<int> ans;
	while (u != 1) {
		ans.pb(u);
		u = par[u];
	}
	ans.pb(1);
	reverse(all(ans));
	for (int s : ans) 
		cout << s << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}