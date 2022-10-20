#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    sort(a.begin(), a.end());

    ll max_sum = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] - max_sum > 1) break;
        max_sum += a[i];
    }
    cout << max_sum + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
