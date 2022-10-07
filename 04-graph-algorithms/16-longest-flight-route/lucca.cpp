/**
    Ideia:
    * Rodar uma DP no grafo com arestas invertidas
    * para encontrar o maior número de vertices no
    * caminho de s ate 1.
    * OBS: antes checar se N e alcançável com DFS/BFS
    Estado da DP:
    * dp[s]: maior número de vertices no caminho de 1 ate s
    Caso base da DP:
    * dp[1] = 0
    Complexidade:
    * O(n)
**/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long int ll;

const int MAXN = 1e5 + 10, INF = 2e9, M = 1e9 + 7;

vector<int> adj[MAXN], rev[MAXN];
bool vis[MAXN];
int dist[MAXN], par[MAXN];

void dfs(int s) {
    if (vis[s]) return;
    vis[s] = true;
    for (int u : adj[s])
        dfs(u);
}

int dp(int s) {
    if (dist[s] != -INF) return dist[s];
    for (int u : rev[s]) {
        int d = dp(u);
        if (d + 1 > dist[s]) {
            dist[s] = d + 1;
            par[s] = u;
        }
    }
    return dist[s];
}

void solve() {
    int n, m; cin >> n >> m;
    while (m--) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        rev[b].pb(a);
    }
    dfs(1);
    if (!vis[n]) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    for (int i = 2; i <= n; ++i) dist[i] = -INF;
    cout << dp(n) + 1 << endl;
    vector<int> ans;
    int s = n;
    while (s != 1) {
        ans.pb(s);
        s = par[s];
    }
    ans.pb(1);
    for (int i = ans.size() - 1; i >= 0; --i)
        cout << ans[i] << ' ';
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}