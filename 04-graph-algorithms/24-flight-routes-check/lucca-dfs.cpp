/**
 Ideia:
 * Duas DFS's: uma no grafo normal e outra
 * no reverso.
 * Se algum node nao for marcado em qualquer
 * DFS, a resposta eh NAO.
**/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
const int MAXN = 1e5 + 10;
 
vector<int> adj[MAXN][2];
bool vis[MAXN];
 
void dfs(int s, int g) {
    for (int u : adj[s][g]) {
        if (vis[u]) continue;
        vis[u] = true;
        dfs(u, g);
    }
}
 
void solve() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a][0].push_back(b);
        adj[b][1].push_back(a);
    }
    vis[1] = true;
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cout << "NO\n";
            cout << "1 " << i << '\n';
            return;
        }
    }
    memset(vis, 0, sizeof(vis));
    vis[1] = true;
    dfs(1, 1);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cout << "NO\n";
            cout << i << " 1\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}