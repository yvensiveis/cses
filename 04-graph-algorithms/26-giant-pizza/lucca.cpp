/**
 * * Problema 2SAT.
 * Resumo:
  * Kosaraju's + Top sort ao contrário definindo
  * os valores verdade.
  * Se, depois do Kosaraju's, encotrar x e ~x no mesmo
  * SSC, a proposição é falsa.
 * OBS:
  * Muuuitos detalhes de implementação.
  * Tomar cuidado com a utilização ou não
  * dos grafos reversos.
  * Calcular direito o número de componentes.
**/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
 
using namespace std;
 
typedef long long int ll;
 
const int MAXM = 1e5 + 10, INF = 2e9, M = 1e9 + 7;
 
vector<pair<int, bool>> adj[MAXM][2], rev[MAXM][2]; // 0: -, 1: +
vector<pair<int, bool>> members[2*MAXM];
set<int> g[2*MAXM];
 
bool vis[MAXM][2];
int comp[MAXM][2], ans[MAXM], outdeg[2*MAXM];
vector<pair<int, int>> processed;
int n, m, cnt;
 
void setup(int s, bool t) {
	if (vis[s][t]) return;
	vis[s][t] = true;
	for (auto [u, r] : adj[s][t])
		setup(u, r);
	processed.pb({s, t});
}
 
void dfs(int s, bool t, int c) {
	comp[s][t] = c;
	members[c].pb({s, t});
	for (auto [u, r] : rev[s][t])
		if (!comp[u][r])
			dfs(u, r, c);
}
 
void generate_components(int s, bool t) {
	if (vis[s][t]) return;
	vis[s][t] = true;
	for (auto [u, r] : adj[s][t]) {
		if (comp[u][r] == comp[s][t]) continue;
		if (!g[comp[u][r]].count(comp[s][t])) {
			g[comp[u][r]].insert(comp[s][t]);
			outdeg[comp[s][t]]++;
		}
		generate_components(u, r);
	}
}
 
void kosaraju() {
	for (int i = 1; i <= m; ++i)
		for (int j = 0; j < 2; ++j)
				setup(i, j);
	reverse(all(processed));
	int cur = 1;
	for (auto [s, t] : processed)
		if (!comp[s][t])
			dfs(s, t, cur++);
	cnt = cur - 1;
	/* Gerar grafo de componentes (reverso) */
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= m; ++i)
		for (int j = 0; j < 2; ++j)
			generate_components(i, j);
}
 
void sat() {
	memset(ans, -1, sizeof(ans));
	queue<int> q;
	for (int i = 1; i <= cnt; ++i)
		if (outdeg[i] == 0)
			q.push(i);
	while (!q.empty()) {
		int s = q.front(); q.pop();
		for (auto [u, r] : members[s])
			if (ans[u] == -1)
				ans[u] = r;
		for (int u : g[s]) {
			outdeg[u]--;
			if (outdeg[u] == 0)
				q.push(u);
		}
	}
}
 
void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		char a, b; int u, v;
		cin >> a >> u >> b >> v;
		bool x = a == '+', y = b == '+';
		adj[u][!x].pb({v, y}); rev[v][y].pb({u, !x});
		adj[v][!y].pb({u, x}); rev[u][x].pb({v, !y});
	}
	kosaraju();
	for (int i = 1; i <= m; ++i) {
		if (comp[i][0] == comp[i][1]) {
			cout << "IMPOSSIBLE\n";
			return;
		}
	}
	sat();
	for (int i = 1; i <= m; ++i) {
		cout << "-+"[ans[i] == -1 ? 0 : ans[i]] << ' ';
	}
	cout << endl;
}
 
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
