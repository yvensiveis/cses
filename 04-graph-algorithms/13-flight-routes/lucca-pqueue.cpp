/**
    Ideia:
    * Dijkstra com vetor de pqueues para guardar 
    * as k menores distâncias.
    Complexidade:
    * O(n + mlogm*logk)
**/

#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long int ll;

const int MAXN = 1e5 + 10, MAXK = 15, M = 1e9 + 7;
const ll INF = 1e18;

vector<pair<int, int>> adj[MAXN];
priority_queue<ll> dist[MAXN];
int n, m, k;

void dijkstra() {
    priority_queue<pair<ll, int>> q; // -dist, node
    dist[1].push(0);
    q.push({0, 1});
    while (!q.empty()) {
        int s = q.top().second; ll d = -q.top().first; q.pop();
        if (d > dist[s].top()) continue;
        for (auto [u, w] : adj[s]) {
            if (dist[u].size() < k) {
                dist[u].push(d + w);
                q.push({-(d+w), u});
            } else if (d+w < dist[u].top()) {
                dist[u].pop();
                dist[u].push(d + w);
                q.push({-(d+w), u});
            }
        }
    }
    vector<ll> ans;
    while (!dist[n].empty()) {
        ans.pb(dist[n].top());
        dist[n].pop();
    }
    for (int i = k-1; i >= 0; --i)
        cout << ans[i] << ' ';
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