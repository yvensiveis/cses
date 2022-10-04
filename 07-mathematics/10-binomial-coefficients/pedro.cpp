#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int M = 1e9 + 7;
const int MAX_N = 1e6 + 1;

int fat[MAX_N];

int fexp(int b, int e) {
    if (e == 0) return 1;
    int f = fexp(b, e >> 1);
    f = ((ll) f * f) % M;
    if (e & 1) f = ((ll) f * b) % M;
    return f;
}

int inv(int n) {
    return fexp(n, M - 2);
}

int choose(int n, int k) {
    return ((ll) fat[n] * inv(((ll) fat[k] * fat[n - k]) % M)) % M;
}

void prep() {
    fat[0] = 1;
    for (int i = 1; i < MAX_N; ++i) {
        fat[i] = ((ll) fat[i - 1] * i) % M;
    }
}

void solve() {
    int n, k; cin >> n >> k;
    cout << choose(n, k) << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    prep();
    int t; cin >> t; while (t--)
    solve();
    return 0;
}
