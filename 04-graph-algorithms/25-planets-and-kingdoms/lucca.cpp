#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long int ll;

const int MAXN = 1e5 + 10, M = 1e9 + 7, INF = 2e9;

vector<int> adj[MAXN], rev[MAXN], order;
bool vis[MAXN];
int comp[MAXN], n, m;

void setup(int s) {
	if (vis[s]) return;
	vis[s] = true;
	for (int u : adj[s])
		setup(u);
	order.pb(s);
}

void dfs(int s, int c) {
	comp[s] = c;
	for (int u : rev[s])
		if (!comp[u])
			dfs(u, c);
}

int kosaraju() {
	for (int i = 1; i <= n; ++i)
		setup(i);
	int cur = 1;
	reverse(all(order));
	for (int u : order)
		if (!comp[u])
			dfs(u, cur++);
	return cur-1;
}

void solve() {
	cin >> n >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		adj[a].pb(b);
		rev[b].pb(a);
	}
	cout << kosaraju() << endl;
	for (int i = 1; i <= n; ++i)
		cout << comp[i] << ' ';
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}