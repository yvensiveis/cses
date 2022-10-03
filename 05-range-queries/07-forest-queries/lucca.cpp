#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long int ll;

const int MAXN = 1010, INF = 2e9, M = 1e9 + 7;

int grid[MAXN][MAXN];
ll pref[MAXN][MAXN];

void solve() {
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            char ch; cin >> ch;
            grid[i][j] = ch == '*';
        }
    pref[0][0] = grid[0][0];
    for (int i = 1; i < n; ++i)
        pref[i][0] = grid[i][0] + pref[i-1][0];
    for (int j = 1; j < n; ++j)
        pref[0][j] = grid[0][j] + pref[0][j-1];
    for (int i = 1; i < n; ++i)
        for (int j = 1; j < n; ++j)
            pref[i][j] = grid[i][j] + pref[i][j-1] + pref[i-1][j] - pref[i-1][j-1];
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;
        ll ans = pref[x2][y2];
        if (y1 >= 1) ans -= pref[x2][y1-1];
        if (x1 >= 1) ans -= pref[x1-1][y2];
        if (x1 >= 1 && y1 >= 1) ans += pref[x1-1][y1-1];
        cout << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}