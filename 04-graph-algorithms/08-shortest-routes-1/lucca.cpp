/**
Aplicacao direta de Dijkstra
**/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long int ll;

const int MAXN = 1e5 + 10, M = 1e9 + 7;
const ll INF = 1e18;

vector<pair<int, int>> adj[MAXN];
ll dist[MAXN];
bool vis[MAXN];
int n, m;

void dijkstra(int x) {
    priority_queue<pair<ll, int>> q;
    for (int i = 1; i <= n; i++) dist[i] = INF;
    dist[x] = 0;
    q.push({0, x});
    while (!q.empty()) {
        int s = q.top().second; q.pop();
        if (vis[s]) continue;
        for (auto [u, w] : adj[s]) {
            if (dist[u] > dist[s] + w) {
                dist[u] = dist[s] + w;
                q.push({-dist[u], u});
            }
        }        
        vis[s] = true;
    }
}

void solve() {
    cin >> n >> m;
    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].pb({b, c});
    }
    dijkstra(1);
    for (int i = 1; i <= n; ++i)
        cout << dist[i] << ' ';
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}