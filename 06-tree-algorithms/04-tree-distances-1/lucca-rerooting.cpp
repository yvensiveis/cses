#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount

using namespace std;

typedef long long int ll;

const int MAXN = 2e5 + 10, INF = 2e9, M = 1e9 + 7;

vector<int> adj[MAXN];
int best_down[MAXN], scnd_down[MAXN];
int best_up[MAXN], child[MAXN], ans[MAXN];

void root(int s, int p) { // melhor usando os filhos
	for (int u : adj[s]) {
		if (u == p) continue;
		root(u, s);
		if (best_down[s] < best_down[u] + 1) {
			scnd_down[s] = best_down[s];
			best_down[s] = best_down[u] + 1;
			child[s] = u;
		} else if (scnd_down[s] < best_down[u] + 1) {
			scnd_down[s] = best_down[u] + 1;
		}
	}
}

void dfs(int s, int p) { // melhor usando o pai
	for (int u : adj[s]) {
		if (u == p) continue;
		best_up[u] = best_up[s] + 1;
		if (child[s] == u) {
			best_up[u] = max(best_up[u], scnd_down[s] + 1);
		} else {
			best_up[u] = max(best_up[u], best_down[s] + 1);
		}
		dfs(u, s);
	}
}

void solve() {
	int n; cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int a, b; cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	root(1, 1);
	dfs(1, 1);
	for (int i = 1; i <= n; ++i) {
		cout << max(best_up[i], best_down[i]) << ' ';
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}