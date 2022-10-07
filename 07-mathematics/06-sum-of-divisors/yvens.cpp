#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int M = 1e9 + 7;

void solve() {
    ll n; cin >> n;
    ll sum = 0, raiz = sqrt(n);
    for(ll d = 1; d*d <= n; d++){
        sum = (sum + d * ((n/d) - raiz)) % M;
    }
    for(ll m = 1; m*m <= n; m++){
        ll p = (n/m) % M;
        sum = (sum + p*(p+1)/2) % M;
    }

    cout << sum << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //int t; cin >> t; while (t--)
    solve();
    return 0;
}
