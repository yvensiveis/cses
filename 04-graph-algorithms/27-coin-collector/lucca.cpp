/**
 * Kosaraju para comprimir o grafo
 * em S.C.C. e depois roda DP.
 * Estado da DP:
 *  dp(u): maior quantidade de moedas
 *  possivel comecando em u.
 * Base da DP:
 *  dp(u) = coins[u], se u tem grau de
 *  saida 0
**/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long int ll;

const int MAXN = 1e5 + 10, INF = 2e9, M = 1e9 + 7;

int k[MAXN], comp[MAXN], n, m;
bool vis[MAXN];
vector<int> adj[MAXN], rev[MAXN], in_comp[MAXN], order;
set<int> g[MAXN];
ll memo[MAXN], coins[MAXN];

void setup(int s) {
    if (vis[s]) return;
    vis[s] = true;
    for (int u : adj[s])
        setup(u);
    order.pb(s);
}

void dfs(int s, int c) {
    in_comp[c].pb(s);
    comp[s] = c;
    coins[c] += k[s];
    for (int u : rev[s])
        if (!comp[u])
            dfs(u, c);
}

int kosaraju() {
    for (int i = 1; i <= n; ++i)
        setup(i);
    reverse(all(order));
    int cur = 1;
    for (int u : order)
        if (!comp[u])
            dfs(u, cur++);
    for (int c = 1; c < cur; ++c)
        for (int s : in_comp[c])
            for (int u : adj[s])
                if (comp[u] != c)
                    g[c].insert(comp[u]);
    return cur - 1;
}

ll dp(int s) {
    if (memo[s] != -1) return memo[s];
    memo[s] = coins[s];
    for (int u : g[s])
        memo[s] = max(memo[s], coins[s] + dp(u));
    return memo[s];
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> k[i];
    while (m--) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        rev[b].pb(a);
    }
    int q = kosaraju();
    memset(memo, -1, sizeof(memo));
    ll ans = 0;
    for (int i = 1; i <= q; ++i)
        ans = max(ans, dp(i));
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}