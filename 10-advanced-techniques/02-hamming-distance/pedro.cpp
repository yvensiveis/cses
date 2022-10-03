#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        a[i] = stoi(s, nullptr, 2);
    }
 
    int ans = k;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int hamming_distance = __builtin_popcount(a[i] ^ a[j]);
            ans = min(ans, hamming_distance);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
