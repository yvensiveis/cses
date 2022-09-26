#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    map<int, int> last_val_idx;
    for (int i = 0; i < n; ++i) {
        last_val_idx[a[i]] = i;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int val = x - (a[i] + a[j]);
            auto it = last_val_idx.find(val);
            if (it != last_val_idx.end()) {
                int k = it->second;
                if (k != 0 && k != i && k != j) {
                    cout << i + 1 << ' ' << j + 1 << ' ' << k + 1 << '\n';
                    return;
                }
            }
        }
    }

    cout << "IMPOSSIBLE\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
