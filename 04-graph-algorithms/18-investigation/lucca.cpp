/**
 Ideia:
 * Dijkstra para pegar o preço mínimo e
 * DP no grafo reverso para as demais perguntas.
 * Struct ajuda a unir as respostas :)
 Estado das DP's:
 * - paths[s]: quandos caminhos de custo mínimo
 * existem de 1 até s
 * - min_edges[s]: número mínimo de arestas em
 * um caminho de custo mínimo de 1 até s
 * - max_edges[s]: número máximo de arestas em
 * um caminho de custo mínimo de 1 até s
 Base da DP:
 * paths[1] = 1;
 * min_edges[1] = 0;
 * max_edges[1] = 0;
 OBS:
 * - Lembrar de so adicionar dp(u) se u faz parte
 * de um caminho mínimo até s;
 * - Tomar cuidado ao implementar as transições;
 * - Não esquecer de tirar o modulo nem de inicializar
 * os nós corretamente.
**/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long int ll;

const int MAXN = 1e5 + 10, M = 1e9 + 7, INF = 1e9;
const ll LL_INF = 1e18;

struct Ans {
    int paths, min_edges, max_edges;
    bool vis;
    Ans operator+(Ans a) const {
        return Ans{
            (paths%M+a.paths%M)%M, 
            min(min_edges, a.min_edges + 1), 
            max(max_edges, a.max_edges + 1)
        };
    }
    void operator+=(Ans a) {
        *this = *this + a;
    }
    void show() {
        cout << paths << ' ' << min_edges << ' ' << max_edges << endl;
    }
};

vector<pair<int, int>> adj[MAXN], rev[MAXN];
ll dist[MAXN];
bool vis[MAXN];
int n, m;
Ans memo[MAXN];

void dijkstra() {
    priority_queue<pair<ll, int>> q; // -dist, node
    for (int i = 2; i <= n; ++i) dist[i] = LL_INF;
    q.push({0, 1});
    while (!q.empty()) {
        int s = q.top().second; q.pop();
        if (vis[s]) continue;
        vis[s] = true;
        for (auto [u, w] : adj[s]) {
            if (dist[u] > dist[s] + w) {
                dist[u] = dist[s] + w;
                q.push({-dist[u], u});
            }
        }
    }
}

Ans dp(int s) {
    if (memo[s].vis) return memo[s];
    for (auto [u, w] : rev[s])
        if (dist[u] + w == dist[s])
            memo[s] += dp(u);
    memo[s].vis = true;
    return memo[s];
}

void solve() {
    cin >> n >> m;
    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].pb({b, c});
        rev[b].pb({a, c});
    }
    dijkstra();
    memo[1] = {1, 0, 0, 1};
    for (int i = 2; i <= n; ++i)
        memo[i] = {0, INF, -INF, 0};
    cout << dist[n] << ' ';
    dp(n).show();
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}