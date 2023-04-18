/*

Achar os vertices que pertencem a todos os caminhos
minimos de 1 a N em um digrafo H

Ideia:

As seguintes afirmacoes sao equivalentes:
a) s pertence a todos os caminhos minimos
b) s eh "vertice de corte" no DAG D gerado pelos caminhos minimos em H
c) s eh vertice de corte em G(D) (grafo subjacente)

*/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount

using namespace std;

typedef long long int ll;

const int maxn = 2e5 + 10, M = 1e9 + 7;
const ll inf = 1e18;

void clear() {
}

vector<pair<int, int>> adj[maxn][2];
vector<int> g[maxn];
ll dist[maxn][2];
bool vis[maxn], cut[maxn];
int n, m;
int tin[maxn], lo[maxn], timer;

void dfs(int s, int p) {
    tin[s] = ++timer;
    lo[s] = timer;
    for (int u : g[s]) {
        if (!tin[u]) {
            dfs(u, s);
            lo[s] = min(lo[s], lo[u]);
        } else if (u != p) {
            lo[s] = min(lo[s], tin[u]);
        }
    }
    if (lo[s] >= tin[p]) cut[p] = 1;
}

void dijkstra(int x, int t) {
    memset(vis, 0, sizeof(vis));
    priority_queue<pair<ll, int>> q;
    for (int i = 1; i <= n; ++i) dist[i][t] = inf;
    dist[x][t] = 0;
    q.push({0, x});
    while (!q.empty()) {
        int s = q.top().second; q.pop();
        if (vis[s]) continue;
        for (auto [u, w] : adj[s][t]) {
            if (dist[u][t] > dist[s][t] + w) {
                dist[u][t] = dist[s][t] + w;
                q.push({-dist[u][t], u});
            }
        }
        vis[s] = true;
    }
}

void solve() {
    clear();
    cin >> n >> m;
    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        adj[a][0].pb({b, c});
        adj[b][1].pb({a, c});
    }
    
    dijkstra(1, 0);
    dijkstra(n, 1);
    for (int i = 1; i <= n; ++i) {
        for (auto [s, w] : adj[i][0]) {
            if (dist[i][0] + w + dist[s][1] == dist[n][0]) {
                g[i].pb(s);
                g[s].pb(i);
            }
        }
    }

    dfs(1, 1);

    vector<int> ans;
    cut[1] = cut[n] = true;
    for (int i = 1; i <= n; ++i)
        if (cut[i])
            ans.pb(i);
    cout << ans.size() << endl;
    for (int x : ans) cout << x << ' '; cout << endl;

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // int t; cin >> t; while (t--)
    solve();
    return 0;
}