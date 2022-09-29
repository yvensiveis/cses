#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int M = 1e9 + 9;
const int P = 31;

int ord(char ch) {
    return ch - 'a' + 1;
}

int fexp(int b, int e) {
    if (e == 0) return 1;
    int f = fexp(b, e >> 1);
    f = ((ll) f * f) % M;
    if (e & 1) f = ((ll) f * b) % M;
    return f;
}

void solve() {
    string a, b; cin >> a >> b;
    int n = a.size(), m = b.size();

    int b_hsh = 0;
    int p = 1;
    for (int i = 0; i < m; ++i) {
        b_hsh = (b_hsh + (ll) ord(b[i]) * p) % M;
        p = ((ll) p * P) % M;
    }

    int p_inv = fexp(P, M - 2);

    int ans = 0;

    int sub_hsh = 0;
    p = 1;
    for (int i = 0; i < n; ++i) {
        if (i < m) {
            sub_hsh = (sub_hsh + (ll) ord(a[i]) * p) % M;
        } else {
            sub_hsh = (sub_hsh - ord(a[i - m]) + M) % M;
            sub_hsh = ((ll) sub_hsh * p_inv) % M;
            sub_hsh = (sub_hsh + (ll) ord(a[i]) * p) % M;
        }

        if (i < m - 1) {
            p = ((ll) p * P) % M;
        } else {
            if (sub_hsh == b_hsh) ++ans;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
