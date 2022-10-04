#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount

using namespace std;

typedef long long int ll;

const int MAXN = 2e5 + 10, INF = 2e9, M = 1e9 + 7;

vector<int> adj[MAXN];
bool vis[MAXN];
int dist[MAXN];

int bfs(int x) {
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(x);
    dist[x] = 0;
    vis[x] = true;
    int v = x;
    while (!q.empty()) {
        int s = q.front(); q.pop();
        for (int u : adj[s]) {
            if (vis[u]) continue;
            vis[u] = true;
            dist[u] = dist[s] + 1;
            if (dist[u] > dist[v]) v = u;
            q.push(u);
        }
    }
    return v;
}

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n-1; ++i) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    cout << dist[bfs(bfs(1))] << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}