#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void solve() {
    ll n; cin >> n;

    ll ans = 0;
    ll p = 1;
    while (p <= n) {
        ll dbl_p = p << 1;
        ans += (n / (dbl_p)) * p + max(0LL, n % dbl_p - p + 1);
        p <<= 1;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
