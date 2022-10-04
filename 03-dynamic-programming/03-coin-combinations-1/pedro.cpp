#include <bits/stdc++.h>
 
using namespace std;

const int M = 1e9 + 7;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> c(n);
    for (int &ci : c) cin >> ci;
 
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
 
    for (int i = 1; i <= x; ++i) {
        for (int ci : c) {
            if (i - ci >= 0) {
                dp[i] = (dp[i] + dp[i - ci]) % M;
            }
        }
    }
 
    cout << dp[x] << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
