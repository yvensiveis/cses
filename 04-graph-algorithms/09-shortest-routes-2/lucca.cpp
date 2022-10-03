#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long int ll;

const int MAXN = 510, M = 1e9 + 7;
const ll INF = 1e18;

ll dist[MAXN][MAXN];
int n, m, q, adj[MAXN][MAXN];

void floyd() {
    for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (i == j) dist[i][j] = 0;
			else if (adj[i][j]) dist[i][j] = adj[i][j];
			else dist[i][j] = INF;
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				dist[i][j] = min(
					dist[i][j],
					dist[i][k] + dist[k][j]
				);
}

void solve() {
    cin >> n >> m >> q;
    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        adj[a][b] = adj[a][b] ? min(adj[a][b], c) : c; // Pode haver mais de uma aresta entre o mesmo par de vertices
        adj[b][a] = adj[b][a] ? min(adj[b][a], c) : c;
    }
    floyd();
    while (q--) {
		int a, b; cin >> a >> b;
		cout << (dist[a][b] == INF ? - 1 : dist[a][b]) << endl;
	}
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}