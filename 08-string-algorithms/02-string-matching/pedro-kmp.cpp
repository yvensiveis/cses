#include <bits/stdc++.h>

using namespace std;

void solve() {
    string a, b; cin >> a >> b;
    int n = a.size(), m = b.size();

    vector<int> lps(m);
    lps[0] = 0;
    for (int i = 1; i < m; ++i) {
        if (a[i] == a[lps[i - 1]]) {
            lps[i] = lps[i - 1] + 1;
        } else {
            lps[i] = 0;
        }
    }

    int ans = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        if (j < m && a[i] == b[j]) {
            ++j;
        } else {
            while (j != 0) {
                j = lps[j - 1];
                if (a[i] == b[j]) {
                    ++j;
                    break;
                }
            }
        }

        if (j == m) ++ans;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
