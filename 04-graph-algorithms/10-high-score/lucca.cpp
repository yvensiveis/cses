/**
 Ideia:
 * A questao pede o caminho de maior custo
 * em um grafo direcionado com arestas de valores
 * negativos, nulos, ou positivos. Podemos inverter
 * o sinal de toda aresta e encontrar o caminho minimo
 * com Bellman-Ford.
 * Para checar se algum ciclo de peso negativo afeta
 * o vertice N, relaxamos as arestas mais N - 1 vezes
 * para propagar "-INF".
**/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long int ll;

const int MAXN = 2550, M = 1e9 + 7;
const ll INF = 1e18;

struct E {
	int a, b, w;
};

ll dist[MAXN];
bool affected[MAXN];

void solve() {
	int n, m; cin >> n >> m;
	vector<E> edges(m);
	for (int i = 0; i < m; ++i) {
		int a, b, w; cin >> a >> b >> w;
		edges[i] = {a, b, -w}; // !! -w
	}
	for (int i = 2; i <= n; ++i) dist[i] = INF;
	for (int i = 0; i < 2*(n-1); ++i) {
		for (E e : edges) {
			if (dist[e.a] == INF) continue;
			if (dist[e.b] > dist[e.a] + e.w) {
				if (i >= n-1) {
                    // Se eh possivel relaxar o vertice apos os n-1 relaxamentos, ha ciclo negativo.
					affected[e.b] = true;
					dist[e.b] = -INF; // Marcar como -INF para propagar aos demais vertices
				} else {
					dist[e.b] = dist[e.a] + e.w;
				}
			}
		}
	}
	cout << (affected[n] ? -1 : -dist[n]) << endl; // Lembrar de trocar o sinal de dist
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}