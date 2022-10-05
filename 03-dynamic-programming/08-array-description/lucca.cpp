#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
 
using namespace std;
 
typedef long long int ll;
 
const int MAXN = 1e5 + 10, MAXM = 110, M = 1e9 + 7;
 
int n, m, x[MAXN], memo[MAXN][MAXM];
 
int dp(int i, int v) {
    if (i == 0) return x[0] == v || !x[0];
    if (x[i] && v != x[i]) return 0;
    int& res = memo[i][v];
    if (res != -1) return res;
    res = dp(i-1, v) % M;
    if (v-1 >= 1) res = (ll(res) + dp(i-1, v-1)) % M;
    if (v+1 <= m) res = (ll(res) + dp(i-1, v+1)) % M;
    return res;
}

void solve() {
    memset(memo, -1, sizeof(memo));
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> x[i];
    int ans = 0;
    for (int i = 1; i <= m; i++) ans = (ll(ans) + dp(n-1, i)) % M;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}