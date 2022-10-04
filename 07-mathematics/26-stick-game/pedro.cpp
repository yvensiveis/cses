#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> p(k);
    for (int &p_i : p) cin >> p_i;

    vector<bool> dp(n + 1);
    dp[0] = false;
    for (int i = 1; i <= n; ++i) {
        dp[i] = false;
        for (int p_j : p) {
            if (i - p_j >= 0 && dp[i - p_j] == false) {
                dp[i] = true;
                break;
            }
        }
    }

    string ans;
    for (int i = 1; i <= n; ++i) {
        ans.push_back("LW"[dp[i]]);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
