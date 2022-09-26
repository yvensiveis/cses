#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 1;
bitset<MAXN> a;

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) a[i] = false;
    for (int i = 0; i < n - 1; ++i) {
        int x; cin >> x;
        a[x] = true;
    }
    for (int i = 1; i <= n; ++i) {
        if (!a[i]) {
            cout << i << '\n';
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
