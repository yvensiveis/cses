/**
    Ideia:
    * Dijkstra com dois estados:
    * 0 - o desconto não foi usado ainda
    * 1 - o desconto já foi usado
**/

#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
 
using namespace std;
 
typedef long long int ll;
 
const int MAXN = 1e5 + 10;
const ll INF = 1e16;
 
vector<pair<int, int>> adj[MAXN];
bool vis[MAXN][2];
ll dist[MAXN][2];
 
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].pb({b, w});
    }
    priority_queue<tuple<ll, bool, int>> q;  // -dist, node
    q.push({0, false, 1});
    for (int i = 2; i <= n; i++) dist[i][false] = dist[i][true] = INF;
    while (!q.empty()) {
        int s = get<2>(q.top());
        bool used = get<1>(q.top());
        q.pop();
        if (vis[s][used] || s == n) continue;
        for (auto [u, w] : adj[s]) {
            if (used == false && dist[u][true] > dist[s][false] + w / 2) {
                dist[u][true] = dist[s][false] + w / 2;
                q.push({-dist[u][true], true, u});
            }
            if (dist[u][used] > dist[s][used] + w) {
                dist[u][used] = dist[s][used] + w;
                q.push({-dist[u][used], used, u});
            }
        }
        vis[s][used] = true;
    }
    cout << dist[n][true] << endl;
}
 
int main() {
    solve();
    return 0;
}