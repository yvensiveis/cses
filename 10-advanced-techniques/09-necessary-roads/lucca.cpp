/*
Encontrar pontes de um grafo
O(nlogn) mas da pra deixar O(n) se tirar o set
e identificar a aresta na lista de adjacencia
*/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount

using namespace std;

typedef long long int ll;

const int maxn = 2e5 + 10, inf = 2e9, M = 1e9 + 7;

vector<int> adj[maxn];
int tin[maxn], tout[maxn], cut[maxn], lo[maxn], p[maxn], timer = 1;
set<pair<int, int>> bridges;

void dfs(int s) {
    tin[s] = timer++;
    lo[s] = tin[s];
    int chd = 0;
    for (int u : adj[s]) {
        if (!tin[u]) {
            chd++;
            p[u] = s;
            dfs(u);
            lo[s] = min(lo[s], lo[u]);
            if (s != 1 && lo[u] >= tin[s])
                cut[s] = true;
            if (lo[u] > tin[s])
                bridges.insert({min(u, s), max(u, s)});
        } else if (u != p[s]) {
            lo[s] = min(lo[s], tin[u]); 
        }
    }
    if (s == 1 && chd >= 2)
        cut[1] = true;
    tout[s] = timer;
}

void solve() {
    int n, m; cin >> n >> m;
    while (m--) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1);
    cout << bridges.size() << endl;
    for (auto [a, b] : bridges)
        cout << a << ' ' << b << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}