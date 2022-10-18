/*
Existencia de um caminho euleriano:
- todas as arestas pertencem ao mesmo componente e:
i)  para todo vertice u, indeg[u] = outdeg[u] ou
ii) existe um unico u com outdeg[u] = indeg[u] + 1,
    existe um unico v com indeg[v] = outdeg[v] + 1 e
    para todo s t.q. s != u e s != v indeg[s] = outdeg[s]
Em i), todo caminho euleriano eh ciclo, e, em ii),
existe um caminho euleriano de u para v
*/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount

using namespace std;

typedef long long int ll;

const int MAXN = 1e5 + 10, MAXM = 2e5 + 10, INF = 2e9, M = 1e9 + 7;

vector<pair<int, int>> adj[MAXN];
vector<int> ans;
int indeg[MAXN], outdeg[MAXN];
bool used_edge[MAXM];

void hierholzer(int s) {
	while (outdeg[s]) {
		while (!adj[s].empty() && used_edge[adj[s].back().second])
			adj[s].pop_back();
		if (!outdeg[s]) break;
		int u = adj[s].back().first, e = adj[s].back().second;
		used_edge[e] = true;
		outdeg[s]--;
		adj[s].pop_back();
		hierholzer(u);
	}
	ans.pb(s);
}

void solve() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		adj[a].pb({b, i});
		outdeg[a]++; indeg[b]++;
	}
	if (outdeg[1] != indeg[1] + 1 || indeg[n] != outdeg[n] + 1) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	for (int i = 2; i < n; ++i)
		if (outdeg[i] != indeg[i]) {
			cout << "IMPOSSIBLE\n";
			return;
		}
	hierholzer(1);
	for (int i = 0; i < m; ++i) // Pode ser substituido por checagem de SCC
		if (!used_edge[i]) {
			cout << "IMPOSSIBLE\n";
			return;
		}
	reverse(all(ans));
	for (int u : ans)
		cout << u << ' ';
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}