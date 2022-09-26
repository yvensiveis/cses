#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    ll sum = a[0];
    ll ans = sum;
    for (int i = 1; i < n; ++i) {
        if (sum < 0) sum = 0;
        sum += a[i];
        ans = max(ans, sum);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
