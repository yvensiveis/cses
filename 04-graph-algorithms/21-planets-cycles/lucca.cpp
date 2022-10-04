/**
 Ideia:
 * Se u esta em um ciclo,
 *  ans[u] = tamanho do ciclo de u
 * Se não,
 *  ans[u] = ans[t[u]] + 1
**/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount

using namespace std;

typedef long long int ll;

const int MAXN = 2e5 + 10, INF = 2e9, M = 1e9 + 7;

int t[MAXN], c[MAXN], dist[MAXN], p[MAXN];
int vis[MAXN];

void dfs(int s, int e, int d) {
    if (c[s] || vis[s] == 2) return;
    if (vis[s] == 1) {
        p[s] = e;
        c[s] = d-dist[s];
        int u = e;
        while (u != s) {
            c[u] = c[s];
            u = p[u];
        }
        return;
    }
    vis[s] = 1;
    dist[s] = d;
    p[s] = e;
    dfs(t[s], s, d+1);
    vis[s] = 2;
}

int calc(int s) {
    if (c[s]) return c[s];
    return c[s] = calc(t[s]) + 1;
} 

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> t[i];
    for (int i = 1; i <= n; ++i)
        if (!vis[i])
            dfs(i, i, 0);
    for (int i = 1; i <= n; ++i)
        cout << calc(i) << ' ';
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}