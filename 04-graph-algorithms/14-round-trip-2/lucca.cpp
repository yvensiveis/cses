/**
    Detecção de ciclos em grafo direcionado.

    Ideia:
    * Marcar nos de acordo com seu estado de processamento:
    * - 0: o no não foi processado
    * - 1: o no está sendo processado
    * - 2: o no ja foi processado
    * Se, durante a DFS, encontrarmos um no no estado 1,
    * encontramos um ciclo.

    Complexidade:
    * O(n) tempo e espaço
**/

#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long int ll;

const int MAXN = 1e5 + 10, INF = 2e9, M = 1e9 + 7;

vector<int> adj[MAXN];
int vis[MAXN], found_cycle;
int par[MAXN], start;

void dfs(int s, int p) {
    if (found_cycle) return;
    if (vis[s] == 1) {
        found_cycle = true;
        start = s;
        par[s] = p;
        return;
    }
    if (vis[s] == 2) return;
    vis[s] = 1;
    par[s] = p;
    for (int u : adj[s]) {
        dfs(u, s);
    }
    vis[s] = 2;
}

void solve() {
    int n, m; cin >> n >> m;
    while (m--) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i])
            dfs(i, 0);
        if (found_cycle) break;
    }
    if (!found_cycle) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    vector<int> ans;
    ans.pb(start);
    int nxt = par[start];
    while (nxt != start) {
        ans.pb(nxt);
        nxt = par[nxt];
    }
    ans.pb(start);
    cout << ans.size() << '\n';
    for (int i = ans.size()-1; i >= 0; --i)
        cout << ans[i] << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}