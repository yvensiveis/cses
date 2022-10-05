#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
 
using namespace std;
 
const int MAXN = 1010, MAXX = 1e5 + 10;

int price[MAXN], pages[MAXN], dp[MAXN][MAXX];

void solve() {
    int n, x; cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> price[i];
    for (int i = 1; i <= n; i++) cin >> pages[i];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            if (!i || !j) continue;
            int a = j >= price[i] ? pages[i] + dp[i - 1][j - price[i]] : 0;
            int b = i == 1 ? 0 : dp[i - 1][j];
            dp[i][j] = max(a, b);
        }
    }
    cout << dp[n][x] << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}