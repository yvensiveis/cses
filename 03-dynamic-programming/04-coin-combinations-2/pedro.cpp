#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> c(n);
    for (int &ci : c) cin >> ci;

    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= x; ++j) {
            if (j == 0) dp[i][j] = 1;
            else if (i == 0) dp[i][j] = 0;
            else if (j - c[i - 1] < 0) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = (dp[i - 1][j] + dp[i][j - c[i - 1]]) % M;
        }
    }
    cout << dp[n][x] << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
