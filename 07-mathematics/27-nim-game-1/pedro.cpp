#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &ai : a) cin >> ai;

    int a_xor = 0;
    for (int ai : a) {
        a_xor ^= ai;
    }
    bool ans = (a_xor != 0);

    cout << (ans ? "first\n" : "second\n");
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--)
    solve();
    return 0;
}
