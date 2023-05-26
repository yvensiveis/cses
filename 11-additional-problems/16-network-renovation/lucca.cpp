#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
const int maxn = 1e5 + 10;
 
vector<int> adj[maxn];
int tin[maxn], tout[maxn], vis[maxn], timer = 0;
 
void dfs(int s, int p) {
    tin[s] = timer++;
    for (int u : adj[s])
        if (u != p)
            dfs(u, s);
    tout[s] = timer;
}
 
void solve() {
    int n; cin >> n;
    for (int i = 0; i < n-1; ++i) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(1, 1);
	
    vector<pair<int, int>> aux;
    for (int i = 1; i <= n; ++i)
        if (adj[i].size() == 1) 
            aux.pb({tin[i], i});
    sort(all(aux));

    int k = aux.size();    
    cout << k/2 + k%2 << endl;

    int i = 0, j = k/2 + k%2;
    while (i < k/2)
        cout << aux[i++].second << ' ' << aux[j++].second << endl;
    if (k % 2)
        cout << aux[0].second << ' ' << aux[i].second << endl;
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}