/**
Numero minimo de arestas para
que exista um caminho entre todos
os nodes e exemplo de arestas.
**/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount

using namespace std;

typedef long long int ll;

const int MAXN = 1e5 + 10, INF = 2e9, M = 1e9 + 7;

vector<int> adj[MAXN];

bool vis[MAXN];

void dfs(int s) {
    if (vis[s]) return;
    vis[s] = true;
    for (int u : adj[s])
        dfs(u);
}

void solve() {
    int n, m; cin >> n >> m;
    while (m--) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vector<int> v;
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        v.pb(i);
        dfs(i);
    }
    n = v.size();
    cout << n - 1 << endl;
    for (int i = 0; i < n - 1; ++i)
        cout << v[i] << ' ' << v[i+1] << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}