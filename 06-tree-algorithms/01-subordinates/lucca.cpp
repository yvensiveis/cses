#include <bits/stdc++.h>
#define pb push_back
 
using namespace std;
 
const int MAXN = 2e5 + 10;
 
vector<int> adj[MAXN];
int ans[MAXN];
 
int dfs(int s, int p) {
    for (int u : adj[s])
        if (u != p)
            ans[s] += dfs(u, s) + 1;
    return ans[s];
}
 
void solve() {
    int n, x; cin >> n;
    for (int i = 2; i <= n; ++i) {
        cin >> x;
        adj[x].pb(i);
    }
    dfs(1, 1);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << endl;
}
 
int main() {
    solve();
    return 0;
}