#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e6 + 1;

int divisors_cnt[MAX_N] = {0};

void prep() {
    for (int i = 1; i < MAX_N; ++i) {
        for (int j = i; j < MAX_N; j += i) {
            ++divisors_cnt[j];
        }
    }
}

void solve() {
    int x; cin >> x;
    int ans = divisors_cnt[x];
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    prep();
    int t; cin >> t; while (t--)
    solve();
    return 0;
}
