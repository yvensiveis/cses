/**
 Ideia:
 * Se tiver apenas uma SCC, a resposta eh YES
 * Do contrario, rodar uma DFS a partir do 1
 * marca todos os alcancaveis. 
 * Se o 1 alcanca um node u de outro componente,
 * u nao alcanca 1 (se nao estariam no mesmo SCC).
**/
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

void mark(int s) {
    if (vis[s]) return;
    vis[s] = true;
    for (int u : adj[s])
        mark(u);
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
	int cnt = kosaraju();
    if (cnt == 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
        memset(vis, 0, sizeof(vis));
        mark(1);
        for (int i = 2; i <= n; ++i) {
            if (comp[i] == comp[1]) continue;
            if (vis[i]) cout << i << " 1\n";
            else cout << "1 " << i << '\n';
            return;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}