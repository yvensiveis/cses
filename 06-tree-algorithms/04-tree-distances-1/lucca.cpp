#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long int ll;

const int MAXN = 2e5 + 10, M = 1e9 + 7, INF = 2e9, LOG = 25;

int dist[2][MAXN];
bool vis[MAXN];

vector<int> adj[MAXN];

/**
 Marca o vetor dist[t] com a distancia
 de todos os vertices ate x e retorna o
 vertice mais distante de x
 */
int bfs(int x, bool t) {
	memset(vis, 0, sizeof(vis));
	queue<int> q;
	q.push(x);
	vis[x] = true;
	int v = x, d = 0;
	dist[t][x] = 0;
	while (!q.empty()) {
		int s = q.front(); q.pop();
		for (int u : adj[s]) {
			if (vis[u]) continue;
			q.push(u);
			vis[u] = true;
			dist[t][u] = dist[t][s] + 1;
			if (dist[t][u] > d) {
				v = u;
				d = dist[t][u];
			}
		}
	}
	return v;
}

void solve() {
	int n; cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int a, b; cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	bfs(bfs(bfs(1, 0), 1), 0);
	for (int i = 1; i <= n; ++i) {
		cout << max(dist[0][i], dist[1][i]) << ' ';
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}