/**
 Aplicacao direta de Hierholzer's para achar
 circuito euleriano.
 OBS:
 * - Da pra usar deque com push_front no lugar de
 * vector com reverse
 * - O algoritmo ALTERA a lista de adjacencia original.
 * Talvez seja preciso guarda uma copia.
 * - Tomar cuidado com a verificacao de existencia do
 * circuito/caminho, varia de acordo com o tipo de grafo
**/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long int ll;

const int MAXN = 1e5 + 10, MAXM = 2e5 + 10, M = 1e9 + 7, INF = 2e9;

vector<pair<int, int>> adj[MAXN];

int deg[MAXN];
bool used_edge[MAXM];
vector<int> ans;

void hierholzer(int s) {
	while (deg[s]) {
		while (!adj[s].empty() && used_edge[adj[s].back().second]) {
			deg[s]--;
			adj[s].pop_back();
		}
		if (deg[s] == 0) {
			ans.push_back(s);
			return;
		}
		int u = adj[s].back().first, e = adj[s].back().second;
		used_edge[e] = true;
		deg[s]--;
		adj[s].pop_back();
		hierholzer(u);
	}
	ans.push_back(s);
}

void solve() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		adj[a].pb({b, i});
		adj[b].pb({a, i});
		deg[a]++, deg[b]++;
	}
	for (int i = 1; i <= n; ++i)
		if (deg[i] % 2) {
			cout << "IMPOSSIBLE\n";
			return;
		}
	hierholzer(1);
	for (int i = 0; i < m; ++i)
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