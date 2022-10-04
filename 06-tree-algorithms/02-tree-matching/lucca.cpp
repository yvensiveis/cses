#include <bits/stdc++.h>
#define pb push_back
 
using namespace std;
 
typedef long long int ll;
 
const int MAXN = 2e5 + 10;
 
vector<int> adj[MAXN], depth[MAXN];
int par[MAXN], max_depth;
bool taken[MAXN];
 
void dfs(int s, int p, int d) {
    par[s] = p;
    depth[d].pb(s);
    max_depth = max(max_depth, d);
    for (int u : adj[s])
        if (u != p)
            dfs(u, s, d+1);
}
 
void solve() {
    int n, a, b; cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1, 0, 1);
    taken[0] = true;
    int cnt = 0;
    for (int i = max_depth; i >= 1; i--) {
        for (int s : depth[i]) {
            if (taken[s] || taken[par[s]]) continue;
            taken[s] = true;
            taken[par[s]] = true;
            cnt++;
        }
    }
    cout << cnt << endl;
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}