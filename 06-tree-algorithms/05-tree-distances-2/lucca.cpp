/*
 Ideia:
 * - A resposta pra um node s eh a soma
 * das profundidades de todos os nodes
 * quando a arvore eh enraizada em s.
 * - Calcula a resposta pra 1.
 * - Quando a raiz muda de s para um filho
 * u, todos os nodes na subarvore de u
 * (quando a raiz eh s) perdem 1 de profundidade,
 * e todos os demais nodes ganham 1 de profundidade.
 * Assim,
 * ans[u] = ans[s] - sz[u] + (n - sz[u])
 *        = ans[s] + n - 2*sz[u]  
 * Sendo sz[u] o tamanho da subarvore de u quando
 * 1 eh a raiz
*/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount

using namespace std;

typedef long long int ll;

const int MAXN = 2e5 + 10, INF = 2e9, M = 1e9 + 7;

vector<int> adj[MAXN];
int sz[MAXN], n;
ll ans[MAXN];

void dfs(int s, int p, int d) {
	ans[1] += d;
	sz[s] = 1;
	for (int u : adj[s])
		if (u != p) {
			dfs(u, s, d+1);
			sz[s] += sz[u];
		}
}

void calc(int s, int p) {
	for (int u : adj[s]) {
		if (u != p) {
            ans[u] = ans[s] + n - 2*sz[u];
            calc(u, s);
        }
	}
}

void solve() {
	cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int a, b; cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(1, 1, 0);
	calc(1, 1);
	for (int i = 1; i <= n; ++i)
		cout << ans[i] << ' ';
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}