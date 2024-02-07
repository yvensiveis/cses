#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define pc __builtin_popcount
#define int long long

using namespace std;

const int maxn = 2e5 + 10, inf = 1e18, M = 1e9 + 7, LOG = 25;

vector<pair<int, int>> adj[maxn];

int lft[maxn], indeg[maxn], outdeg[maxn], dir[maxn];
int tin[maxn], timer;

// dir = 1: ancestral pro filho, dir = 2: filho pro ancestral

/**
 * Orienta as back edges "pra baixo" e
 * resolve para a árvore
*/

void dfs(int s, int p) {
    tin[s] = ++timer;
    for (auto [u, i] : adj[s]) {
        if (u == p) continue;
        if (!tin[u]) {
            dfs(u, s);
        } else if (tin[u] < tin[s]) { // back edge
            dir[i] = 1;
            lft[u]--; lft[s]--;
            outdeg[u]++; indeg[s]++;
        }
    }
}

void solve() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        adj[a].pb({b, i});
        adj[b].pb({a, i});
        lft[a]++; lft[b]++;
        edges.pb({a, b});
    }
    for (int i = 1; i <= n; ++i)
        if (!tin[i])
            dfs(i, i);
    queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (lft[i] == 1)
            q.push(i);
    while (!q.empty()) {
        int s = q.front(); q.pop();
        for (auto [u, i] : adj[s]) {
            if (dir[i]) continue;
            lft[s]--; lft[u]--;
            if (lft[u] == 1) q.push(u);
            if (outdeg[s] % 2) {
                outdeg[s]++;
                indeg[u]++;
                if (tin[s] < tin[u]) dir[i] = 1;
                else dir[i] = 2;
            } else {
                outdeg[u]++;
                indeg[s]++;
                if (tin[s] < tin[u]) dir[i] = 2;
                else dir[i] = 1;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        if (outdeg[i] % 2) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    for (int i = 0; i < m; ++i) {
        int a = edges[i].first, b = edges[i].second;
        if (tin[a] > tin[b]) swap(a, b);
        if (dir[i] == 2) swap(a, b);
        cout << a << ' ' << b << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    solve();
}