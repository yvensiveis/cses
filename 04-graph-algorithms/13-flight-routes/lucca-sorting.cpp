/**
    Ideia:
    * Dijkstra com vetor de vectors para guardar 
    * as k menores distâncias, dando sort a cada
    * alteração de distância.
    Complexidade:
    * O((n + mlogm)*klogk)
**/

#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long int ll;

const int MAXN = 1e5 + 10, MAXK = 15, M = 1e9 + 7;
const ll INF = 1e18;

vector<pair<int, int>> adj[MAXN];
vector<ll> dist[MAXN];
int n, m, k;

void dijkstra() {
    for (int i = 1; i <= n; ++i) {
        dist[i].resize(k);
        for (int j = 0; j < k; ++j)
            dist[i][j] = INF;
    }
    dist[1][0] = 0;
    priority_queue<pair<ll, int>> q; // -dist, node
    q.push({0, 1});
    while (!q.empty()) {
        int s = q.top().second; ll d = -q.top().first; q.pop();
        if (dist[s][k-1] < d) continue;
        for (auto [u, w] : adj[s]) {
            if (dist[u][k-1] > d + w) {
                dist[u][k-1] = d + w;
                q.push({-dist[u][k-1], u});
                sort(all(dist[u]));
            }
        }
    }
    for (int i = 0; i < k; ++i)
        cout << dist[n][i] << ' ';
    cout << endl;
}

void solve() {
    cin >> n >> m >> k;
    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].pb({b, c});
    }
    dijkstra();
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}