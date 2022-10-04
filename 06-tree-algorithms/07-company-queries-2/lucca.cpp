#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
 
using namespace std;
 
typedef long long int ll;
 
const int MAXN = 2e5 + 10, INF = 2e9, M = 1e9 + 7, LOG = 25;
 
int anc[MAXN][LOG], depth[MAXN];
vector<int> adj[MAXN];
 
void dfs(int s) {
    for (int u : adj[s]) {
        depth[u] = depth[s] + 1;
        dfs(u);
    }
}
 
int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    int k = depth[a] - depth[b];
    for (int i = 0; i < LOG; ++i)
        if (k & (1 << i))
            a = anc[a][i];
    if (a == b) return a;
    for (int i = LOG-1; i >= 0; --i) {
        if (anc[a][i] == anc[b][i]) {
            continue;
        }
        a = anc[a][i];
        b = anc[b][i];
    }
    return anc[a][0];
}
 
void solve() {
    int n, q; cin >> n >> q;
    for (int i = 2; i <= n; ++i) {
        cin >> anc[i][0];
        adj[anc[i][0]].pb(i);
    }
    for (int i = 1; i < LOG; ++i)
        for (int s = 1; s <= n; ++s)
            anc[s][i] = anc[anc[s][i-1]][i-1];
    dfs(1);
    while (q--) {
        int a, b; cin >> a >> b;
        cout << lca(a, b) << endl;
    }
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}