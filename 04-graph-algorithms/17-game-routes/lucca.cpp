/**
 Ideia:
 * DP no grafo reverso.
 Estado da DP:
 * dp[s]: quantos caminhos vão de 1 até s
 Base da DP:
 * dp[1] = 1;
**/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long int ll;

const int MAXN = 1e5 + 10, INF = 2e9, M = 1e9 + 7;

vector<int> rev[MAXN];
int cnt[MAXN];

int dp(int s) {
    if (cnt[s]) return cnt[s];
    for (int u : rev[s])
        cnt[s] = (cnt[s] + dp(u)) % M;
    return cnt[s];
}

void solve() {
    int n, m; cin >> n >> m;
    while (m--) {
        int a, b; cin >> a >> b;
        rev[b].pb(a);
    }
    cnt[1] = 1;
    cout << dp(n) << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}