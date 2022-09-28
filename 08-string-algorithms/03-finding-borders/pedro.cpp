#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll MOD = (ll) 1e18 + 3;

void solve() {
    string a; cin >> a;
    int n = a.size();
 
    ll pfx_hash = 0, sfx_hash = 0;
    ll pow26 = 1;
    for (int i = 0; i < n - 1; ++i) {
        pfx_hash = (((__int128) pfx_hash * 26) + (a[i] - 'a')) % MOD;
        sfx_hash = (sfx_hash + (__int128) pow26 * (a[n - i - 1] - 'a')) % MOD;
        pow26 = ((__int128) pow26 * 26) % MOD;
        if (pfx_hash == sfx_hash) {
            cout << i + 1 << ' ';
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
