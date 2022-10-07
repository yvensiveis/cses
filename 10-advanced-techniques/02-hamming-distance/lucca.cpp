/**
* Sacada: hamming distance entre duas strings binárias
* eh igual ao popcount do xor.
**/

#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long int ll;

const int MAXN = 1e5 + 10, INF = 2e9, M = 1e9 + 7;

int conv(string s) {
    int res = 0;
    for (int i = 0; i < s.size(); ++i)
        if (s[i] == '1')
            res |= (1 << i);
    return res;
}

void solve() {
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        string s; cin >> s; reverse(all(s));
        v[i] = conv(s);
    }
    int ans = 30;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            ans = min(ans, __builtin_popcount(v[i]^v[j]));
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}