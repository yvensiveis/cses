#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll M = (ll) 1e18 + 3;
const int P = 31;

int ord(char ch) {
    return ch - 'a' + 1;
}

void solve() {
    string a; cin >> a;
    int n = a.size();
 
    ll pfx_hash = 0, sfx_hash = 0;
    ll pow_of_p = 1;
    for (int i = 0; i < n - 1; ++i) {
        pfx_hash = ((__int128) pfx_hash * P + ord(a[i])) % M;
        sfx_hash = (sfx_hash + (__int128) pow_of_p * ord(a[n - i - 1])) % M;
        
        pow_of_p = ((__int128) pow_of_p * P) % M;

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
