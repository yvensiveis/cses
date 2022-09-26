#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void solve() {
    ll n; cin >> n;
    cout << n;
    while (n != 1) {
        if (n & 1) n = n * 3 + 1;
        else n >>= 1;
        cout << ' ' << n;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
