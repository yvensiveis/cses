#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, q; cin >> n >> q;
    vector<string> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    
    vector<vector<int>> prefix_sum_matrix(n, vector<int>(n + 1));
    for (int i = 0; i < n; ++i) {
        prefix_sum_matrix[i][0] = 0;
        for (int j = 1; j <= n; ++j)
            prefix_sum_matrix[i][j] = prefix_sum_matrix[i][j - 1] + (a[i][j - 1] == '*');
    }

    while (q--) {
        int y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;
        --y1; --x1; --y2; --x2;
        int ans = 0;
        for (int i = y1; i <= y2; ++i) {
            ans += prefix_sum_matrix[i][x2 + 1] - prefix_sum_matrix[i][x1];
        }
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
