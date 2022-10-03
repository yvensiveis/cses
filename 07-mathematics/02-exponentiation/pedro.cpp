#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int M = 1e9 + 7;

int fexp(int a, int b) {
    if (b == 0) return 1;
    int f = fexp(a, b >> 1);
    f = ((ll) f * f) % M;
    if (b & 1) f = ((ll) f * a) % M;
    return f;
}

void solve() {
    int a, b; cin >> a >> b;
    cout << fexp(a, b) << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--)
    solve();
    return 0;
}
